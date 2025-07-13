from setuptools import find_packages, setup

package_name = 'my_py_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='abood',
    maintainer_email='anaalbakatoshy.gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "py_node = my_py_pkg.my_first_node:main",
            "publisher_test = my_py_pkg.publisher_test:main",
            "subsrciber_test = my_py_pkg.subscriber_test:main",
            "number_pub = my_py_pkg.number_pub:main",
            "number_sub = my_py_pkg.number_sub:main",
            "add_two_ints_server = my_py_pkg.add_two_ints_server:main",
            "add_two_ints_client_no_OOP = my_py_pkg.add_two_ints_client_no_OOP:main",
            "add_two_ints_client = my_py_pkg.add_two_ints_client:main",
            "reset_counter_client = my_py_pkg.reset_counter_client:main",
            "Hardware_Status_Publisher = my_py_pkg.Hardware_Status_Publisher:main",
            "led_panel = my_py_pkg.led_panel:main",
            "battery = my_py_pkg.battery:main",

            
        ],
    },
)
