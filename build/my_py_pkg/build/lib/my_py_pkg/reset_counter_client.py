#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from example_interfaces.srv import SetBool

class ResetCounterClient(Node):
    def __init__(self):
        super().__init__("reset_counter_client")
        self.client_ = self.create_client(SetBool, "reset_counter")

    def callBackResetNumber(self, data):
        while not self.client_.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn("Waiting for reset_counter server...")

        request = SetBool.Request()
        request.data = data

        future = self.client_.call_async(request)
        future.add_done_callback(self.callBack_call_ResetNumber)

    def callBack_call_ResetNumber(self, future):
        try:
            response = future.result()
            self.get_logger().info(f"Success: {response.success}, Message: {response.message}")
        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = ResetCounterClient()
    node.callBackResetNumber(True)
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
