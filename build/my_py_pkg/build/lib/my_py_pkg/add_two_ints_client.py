#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts
from functools import partial

class AddTwoIntsClient(Node):
    def __init__(self):
        super().__init__("add_two_ints_client")
        self.client_ = self.create_client(
            AddTwoInts , "add_two_ints"
        )

    def callBack_add_two_Ints(self , a , b):
        while not self.client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Add two ints server....")
        
        request = AddTwoInts.Request()
        request.a = a
        request.b = b

        future = self.client_.call_async(request)    
        future.add_done_callback(partial(self.callBack_call_add_two_Ints , request =request))


    def callBack_call_add_two_Ints(self , future , request):
        response =future.result()
        self.get_logger().info(f"{request.a} + {request.b} = {response.sum} ")

def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsClient()
    node.callBack_add_two_Ints(7,2)
    node.callBack_add_two_Ints(3,3) 
    node.callBack_add_two_Ints(9,8) 
    node.callBack_add_two_Ints(5,1)              
    rclpy.spin(node)
    rclpy.shutdown


if __name__ == '__main__':
    main()    