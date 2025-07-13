#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_interfaces.msg import LedStateArray
from my_interfaces.srv import SetLed

class LedPanel(Node):
    def __init__(self):
        super().__init__("led_panel")
        self.declare_parameter("led_states_" , [0,0,0])
        self.led_states_ = self.get_parameter("led_states_").value
        self.led_state_pub_ = self.create_publisher(
            LedStateArray , "led_panel_state" , 10
        )        
        self.timer_ = self.create_timer (5.0 , self.pub_state)

        self.set_led_service = self.create_service(
                SetLed , "set_led" , self.callBack_set_led
        )

        self.get_logger().info("led panel Node starts! ")


    def pub_state(self):
        msg = LedStateArray()
        msg.led_states = self.led_states_
        self.led_state_pub_.publish(msg)

    def callBack_set_led(self , request:SetLed.Request , response:SetLed.Response ):
        led_number = request.led_number
        state = request.state

        if((led_number >len(self.led_states_))or (led_number<0)):
            response.success = False
            return response
        
        if state not in [0,1]:
            response.success = False
            return response
        
        self.led_states_[led_number] = state
        self.pub_state()
        response.success = True
        return response


def main(args=None):
    rclpy.init(args=args)
    node = LedPanel()
    rclpy.spin(node)
    rclpy.shutdown() 

if __name__ == '__main__':
    main()           