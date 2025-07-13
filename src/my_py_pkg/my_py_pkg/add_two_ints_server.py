#!/usr/bin/env python3


import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts 

class AddTwoIntsServer(Node):
    def __init__(self):
        super().__init__("add_two_ints_server")
        self.server_ = self.create_service(
            AddTwoInts , "add_two_ints" , self.callBack_add_two_ints
        )
        self.get_logger().info("add_two_ints_server Has Been Started!")

    def callBack_add_two_ints(self , request: AddTwoInts.Request , respone: AddTwoInts.Response):
      respone.sum = request.a + request.b
      self.get_logger().info(f"{request.a} + {request.b} = {respone.sum} ")
      return respone
      

def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsServer()
    rclpy.spin(node)
    rclpy.shutdown() 

if __name__ == '__main__':
    main()           