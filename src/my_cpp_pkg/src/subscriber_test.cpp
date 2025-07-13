#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::placeholders;


class SubscriberTest : public rclcpp::Node 
{
public:
    SubscriberTest() : Node("cpp_test") 
    {
        subsrciber_ = this->create_subscription<example_interfaces::msg::String>("my_topic" ,
            10,
            std::bind(&SubscriberTest::sub_callback , this ,_1) ) ;
        RCLCPP_INFO(this->get_logger() , "subscriber started");       
    }
private:
void sub_callback(const example_interfaces::msg::String::SharedPtr msg){
    RCLCPP_INFO(this->get_logger() , "%s",msg->data.c_str());
}

rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subsrciber_;
};


int main(int argc , char **argv)
{
    rclcpp::init(argc , argv);
    auto node = std::make_shared<SubscriberTest>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
} 