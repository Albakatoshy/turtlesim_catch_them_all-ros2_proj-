import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class SubsrciberTest(Node):
    def __init__(self):
        super().__init__("Subsrciber_test")
        self.subscriber_ = self.create_subscription(
            String , "my_topic" , self.sub_CallBack , 10
        )

    def sub_CallBack(self , msg:String):
        
        self.get_logger().info(msg.data)


def main(args=None):
    rclpy.init(args=args)
    node = SubsrciberTest()
    rclpy.spin(node)
    rclpy.shutdown() 

if __name__ == '__main__':
    main()  