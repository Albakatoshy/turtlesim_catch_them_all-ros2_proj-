import rclpy
from rclpy.node import Node
from my_interfaces.msg import LedStateArray
from my_interfaces.srv import SetLed


class BatteryNode(Node):
    def __init__(self):
        super().__init__("battery")
        self.battery_state_ = "full"
        self.last_time_battery_state_change = self.get_current_time_in_seconds()
        self.battery_timer_ = self.create_timer(
            0.1 , self.check_battery_state
        )
        self.get_logger().info("Battery node started!")
        self.battery_client_ = self.create_client(
            SetLed , "set_led" 
        )    

    def get_current_time_in_seconds(self):
        seconds , nanoseconds = self.get_clock().now().seconds_nanoseconds()
        return seconds+nanoseconds/1000000000.0

    def check_battery_state(self):
        time_now = self.get_current_time_in_seconds()
        if self.battery_state_ =="full":
            if(time_now - self.last_time_battery_state_change > 4.0):
                self.battery_state_ = "empty"
                self.get_logger().info("Battery is empty!")
                self.set_led(2 , 1)
                self.last_time_battery_state_change = time_now
        elif self.battery_state_ == "empty":
            if(time_now-self.last_time_battery_state_change>6.0):
                self.battery_state_ = "full"
                self.get_logger().info("Battery is Full!")
                self.set_led(2 , 0)
                self.last_time_battery_state_change = time_now

    def set_led(self , led_number , state ):
        while not self.battery_client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for set_led server....")

        request = SetLed.Request()
        request.led_number = led_number
        request.state = state

        future = self.battery_client_.call_async(request)
        future.add_done_callback(self.future_done_callback)

    def future_done_callback(self , future):
        response:SetLed.Response = future.result()    
        if response.success:
            self.get_logger().info(f"Led turn on")
        else:    
            self.get_logger().info(f"Led turn off")

def main(args=None):
    rclpy.init(args=args)
    node = BatteryNode()
    rclpy.spin(node)
    rclpy.shutdown() 

if __name__ == '__main__':
    main()           