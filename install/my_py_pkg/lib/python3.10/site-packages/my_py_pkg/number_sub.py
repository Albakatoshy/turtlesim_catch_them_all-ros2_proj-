#!/usr/bin/env python3


import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int16
from example_interfaces.srv import SetBool

class NumberSub(Node):
    def __init__(self):
        super().__init__("py_test")
        self.counter_ = 0
        self.pub_counter = self.create_publisher(
            Int16 , "counter" , 10
        )
        self.sub_ = self.create_subscription(
            Int16 , "numbers" , self.sub_callBack , 10
        )
        self.server_ = self.create_service(
            SetBool , "reset_counter" ,self.callBack_serviceServer
        )
        self.get_logger().info("the server is been started!")
        

    def sub_callBack(self,msg:Int16):
        self.get_logger().info(f"the data is: {msg.data} ")
        counter_msg = Int16()
        counter_msg.data = self.counter_
        self.counter_+=1
        self.pub_counter.publish(counter_msg)
        

    def callBack_serviceServer(self , request: SetBool.Request , response: SetBool.Response):
        if(request.data == True):
            self.counter_ = 0
            response.success = True
            response.message = "Counter has been reset"

        else:
            response.success = False
            response.message = "Counter has not been reset"
        return response            
                





def main(args=None):
    rclpy.init(args=args)
    node = NumberSub()
    rclpy.spin(node)
    rclpy.shutdown() 

if __name__ == '__main__':
    main()           