from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    ld = LaunchDescription()
    param_config = os.path.join(get_package_share_directory("my_robot_bringup") , "config" , "number_app.yaml")

    number_pub = Node(
        package="my_py_pkg",
        executable="number_pub",
        name="test_change_node_name",
        remappings=[("/numbers" , "/test_change_topic_name")],
        # parameters=[
        #     {"number":12},
        #     {"timer_period":1.3}
        # ]
        #another method to load parameters
        parameters=[param_config]

    )

    number_sub = Node(
        package="my_py_pkg",
        executable="number_sub"
    )

    ld.add_action(number_pub)
    ld.add_action(number_sub)  

    return ld