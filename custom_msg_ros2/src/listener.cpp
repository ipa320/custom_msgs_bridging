#include <memory>

#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp"
#include "custom_msg_ros2/msg/custom_message.hpp"
//using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
      subscription_ = this->create_subscription<custom_msg_ros2::msg::CustomMessage>(
      "chatter", 10, [this](custom_msg_ros2::msg::CustomMessage::UniquePtr msg){
          RCLCPP_INFO(this->get_logger(),"I heard: '%lf'",msg->custom_value);
      });
    }

  private:
    
    rclcpp::Subscription<custom_msg_ros2::msg::CustomMessage>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}