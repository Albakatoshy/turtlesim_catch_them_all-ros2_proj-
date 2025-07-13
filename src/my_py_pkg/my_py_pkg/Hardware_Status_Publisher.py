#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_interfaces.msg import HardwareStatus



class HardwareStatusPublisher(Node):
    def __init__(self):
        super().__init__("hardware_status_publisher")
        self.pub_ = self.create_publisher(
            HardwareStatus , "hardware_status_publisher" , 10
        )
        self.timer_ = self.create_timer(1.0 , self.pub_CallBack)

    def pub_CallBack(self):
        msg = HardwareStatus()
        msg._tempreture = 10.0
        msg._are_motors_ready = True
        msg.debug_message = "done"

        self.pub_.publish(msg)
            

def main(args=None):
    rclpy.init(args=args)
    node = HardwareStatusPublisher()
    rclpy.spin(node)
    rclpy.shutdown() 

if __name__ == '__main__':
    main()           