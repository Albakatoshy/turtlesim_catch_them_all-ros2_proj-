#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::chrono_literals;

class PublisherTest : public rclcpp::Node 
{
public:
    PublisherTest() : Node("publisher_test") 
    {
        publisher_ = this->create_publisher<example_interfaces::msg::String>("my_topic" , 10 );
        timer_ = this->create_wall_timer(0.5s , std::bind(&PublisherTest::publsish_data , this));
        RCLCPP_INFO(this->get_logger() , "publsiher started");
    }
private:
    void publsish_data(){
        auto msg = example_interfaces::msg::String();
        msg.data = "Hello from cpp pub";
        publisher_->publish(msg);
    }

  rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc , char **argv)
{
    rclcpp::init(argc , argv);
    auto node = std::make_shared<PublisherTest>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
} 