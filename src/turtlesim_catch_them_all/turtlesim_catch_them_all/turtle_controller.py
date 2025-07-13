import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
import math
from my_interfaces.msg import Turtle , TurtleArray
from turtlesim.srv import Kill
from my_interfaces.srv import CatchTurtle
from functools import partial

class TurtleController(Node):
    def __init__(self):
        super().__init__("turtle_controller")
        self.declare_parameter("catch_closest_turtle_first" , True)
        self.catch_closest_turtle_first = self.get_parameter("catch_closest_turtle_first").value
        self.turtle_to_catch:Turtle = None
        self.pose :Pose = None
        self.pose_sub = self.create_subscription(
            Pose , "/turtle1/pose" , self.turtle_pose_callback ,10
        )
        self.cmd_pub = self.create_publisher(
            Twist , "/turtle1/cmd_vel" , 10
        )
        self.control_loop_timer = self.create_timer(0.01,self.control_loop)

        self.alive_turtle_sub = self.create_subscription(
            TurtleArray , "alive_turtles" , self.sub_alive_turtle , 10
        )
        self.catch_turtle_client = self.create_client(
            CatchTurtle , "catch_turtle" 
        )

    def sub_alive_turtle(self , msg:TurtleArray):
        if len(msg.turtles)>0:
            if self.catch_closest_turtle_first:
                closest_turtle = None
                closest_turtle_dist = None

                for turtle in msg.turtles:
                    dist_x = turtle.x - self.pose.x
                    dist_y = turtle.y - self.pose.y
                    dist   = math.sqrt(dist_x*dist_x + dist_y*dist_y)
                    if closest_turtle == None or dist < closest_turtle_dist:
                        closest_turtle = turtle
                        closest_turtle_dist = dist
                         
                self.turtle_to_catch = closest_turtle         
            else:
                self.turtle_to_catch = msg.turtles[0]

    def turtle_pose_callback(self , pose:Pose):
        self.pose = pose

   


    def control_loop(self):
        if self.pose == None or self.turtle_to_catch == None: 
            return
        dist_x = self.turtle_to_catch.x - self.pose.x
        dist_y = self.turtle_to_catch.y - self.pose.y
        dist   = math.sqrt(dist_x*dist_x + dist_y*dist_y)

        cmd = Twist()
        if dist > 0.05:
            cmd.linear.x = 2*dist
            self.turtle_to_catch.theta = math.atan2(dist_y , dist_x)
            diff = self.turtle_to_catch.theta - self.pose.theta
            
            if diff > math.pi:
                diff -= 2*math.pi
            elif diff < -math.pi:
                diff += 2*math.pi

            cmd.angular.z = 6*diff
        else:
            self.get_logger().info("targer reached!")
            cmd.linear.x = 0.0
            cmd.angular.z = 0.0
            self.call_catch_turtle_service(self.turtle_to_catch.name)
            self.turtle_to_catch = None

        self.cmd_pub.publish(cmd)

    def call_catch_turtle_service(self , name):
        while not self.catch_turtle_client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for kill server....")
        request = CatchTurtle.Request()
        request.name = name

        future = self.catch_turtle_client.call_async(request)
        future.add_done_callback(partial(self.callbak_call_catch_turtle_service , name = name ) )

    def callbak_call_catch_turtle_service(self, future, name):
        response: CatchTurtle.Response = future.result()
        if not response.success:
            self.get_logger().error(f"Turtle {name} not removed!!")
        




def main(args=None): 
    rclpy.init(args=args)
    node = TurtleController()
    rclpy.spin(node)
    rclpy.shutdown() 

if __name__ == '__main__':
    main()           