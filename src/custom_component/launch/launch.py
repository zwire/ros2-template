from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="custom_component",
            executable="exe",
            output="screen",
            emulate_tty=True,
        ),
    ])