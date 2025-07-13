import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class PublisherTest(Node):
    def __init__(self):
        super().__init__("publisher_test")
        self.publisher_ = self.create_publisher(
            String , "my_topic" , 10 
        )
        self.timer_ = self.create_timer(
            0.5 , self.publish_data
        )
        self.get_logger().info("Publisher started!")

    def publish_data(self):
        msg = String()
        msg.data = "Helloooo"
        self.publisher_.publish(msg)


def main(args=None): 
    rclpy.init(args=args)
    node = PublisherTest()
    rclpy.spin(node)
    rclpy.shutdown() 

if __name__ == '__main__':
    main()           