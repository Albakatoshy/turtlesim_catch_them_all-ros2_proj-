#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int16
from rclpy.parameter import Parameter

class NumberPub(Node):
    def __init__(self):
        super().__init__("number_pub")
        self.declare_parameter(
            "number" , 2 
        )
        self.declare_parameter(
            "timer_period" , 1.0
        )
        self.number_ = self.get_parameter("number").value
        self.timer_period = self.get_parameter("timer_period").value

        self.add_on_set_parameters_callback(self.parametrs_callBack)

        self.pub_ = self.create_publisher(
            Int16 , "numbers" , 10 
        )
        self.timer_ = self.create_timer(
            self.timer_period , self.publish_data
        )

    def parametrs_callBack(self , params: list[Parameter]):
        for param in params:
            if param.name == "number":
                self.number_ = param.value
                

         

    def publish_data(self):
        msg = Int16()
        msg.data = self.number_
        self.pub_.publish(msg)    
        


def main(args=None):
    rclpy.init(args=args)
    node = NumberPub()
    rclpy.spin(node)
    rclpy.shutdown() 

if __name__ == '__main__':
    main()           