import rclpy
from rclpy.node import Node
from turtlesim.srv import Spawn
from functools import partial
import random
import math
from my_interfaces.msg import Turtle , TurtleArray
from my_interfaces.srv import CatchTurtle
from turtlesim.srv import Kill

class TurtleSpawner(Node):
    def __init__(self):
        super().__init__("turtle_spawner")
        self.declare_parameter("turtle_prefix" , "turtle")
        self.turtle_name_prefix = self.get_parameter("turtle_prefix").value
        self.counter_ = 0
        self.alive_turtles = []
        self.declare_parameter("timer_period" , 0.9)
        timer_period = self.get_parameter("timer_period").value 
        self.timer_ = self.create_timer(timer_period , self.spawn_new_turtle)
        self.spawn_client = self.create_client(
            Spawn , "/spawn" 
        )
        
        self.turtle_catch_service = self.create_service(
            CatchTurtle , "catch_turtle" , self.callback_catch_turtle
        )

        self.turtle_kill_client = self.create_client(
            Kill , "kill"
        )

        self.alive_turtles_pub = self.create_publisher(
            TurtleArray , "alive_turtles" , 10
        )

    def callback_catch_turtle(self , request:CatchTurtle.Request , response:CatchTurtle.Response):
        self.call_kill_service(request.name)
        response.success = True
        return response


    def pub_alive_turtles(self):
        msg = TurtleArray()
        msg.turtles = self.alive_turtles
        self.alive_turtles_pub.publish(msg)
    

    def spawn_new_turtle(self):
        self.counter_+=1
        name = self.turtle_name_prefix + str(self.counter_)
        x = random.uniform(0.0 , 11.0)
        y = random.uniform(0.0 , 11.0)
        theta = random.uniform(0.0 , 2 * math.pi)

        self.call_spawn_service(name,x,y,theta)

    def call_spawn_service(self ,turtle_name , x , y , theta ):
        while not self.spawn_client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for turtle_spawner server....")

        request = Spawn.Request()
        request.name = turtle_name
        request.x = x
        request.y = y
        request.theta = theta
           

        future = self.spawn_client.call_async(request) 
        future.add_done_callback(partial(self.callback_call_spawn_service , request = request))

    def callback_call_spawn_service(self , future , request:Spawn.Request):
        response:Spawn.Response = future.result()
        if response.name !="":
            self.get_logger().info(f"New alive turtle->{response.name}")
            new_turtle = Turtle()
            new_turtle.name = response.name
            new_turtle.x = request.x
            new_turtle.y = request.y
            new_turtle.theta = request.theta
            self.alive_turtles.append(new_turtle)
            self.pub_alive_turtles()

    def call_kill_service(self , name):
        while not self.turtle_kill_client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for kill server....")
        request = Kill.Request()
        request.name = name

        future = self.turtle_kill_client.call_async(request)
        future.add_done_callback(partial(self.callbak_call_kill_service , name = name ) )

    def callbak_call_kill_service(self ,future , name):
        for i , turtle in enumerate (self.alive_turtles):
            if turtle.name == name:
                del self.alive_turtles[i]
                self.pub_alive_turtles()
                break

    

def main(args=None): 
    rclpy.init(args=args)
    node = TurtleSpawner()
    rclpy.spin(node)
    rclpy.shutdown() 

if __name__ == '__main__':
    main()           