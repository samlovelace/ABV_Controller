
#include "RosTopicManager.h"

RosTopicManager::RosTopicManager(/* args */) : Node("ABV_Controller")
{
}

RosTopicManager::~RosTopicManager()
{
    rclcpp::shutdown();
}

void RosTopicManager::init()
{
    mPublisher = this->create_publisher<std_msgs::msg::String>("abv_controller", 10);
}

void RosTopicManager::publish(std::string aMsg)
{
    auto msg = std_msgs::msg::String();
    msg.data = aMsg;
    mPublisher->publish(msg);
}

void RosTopicManager::createSubscriber(const std::string& topic_name,
                                    std::function<void(const std_msgs::msg::String::SharedPtr)> callback) 
{
    // Create the subscriber with the passed callback
    mModeSubscriber = this->create_subscription<std_msgs::msg::String>(
        topic_name, 10, callback
    );
}