
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
    //mPublisher = this->create_publisher<std_msgs::msg::String>("abv_controller", 10);
}

void RosTopicManager::createModeSubscriber(const std::string& topic_name,
                                    std::function<void(const std_msgs::msg::String::SharedPtr)> callback) 
{
    // Create the subscriber with the passed callback
    mModeSubscriber = this->create_subscription<std_msgs::msg::String>(topic_name, 10, callback);
}

void RosTopicManager::createInputSubscriber(const std::string& topic_name,
                          std::function<void(const std_msgs::msg::Float64MultiArray::SharedPtr)> callback)
{
    // Create the subscriber with the passed callback
    mInputSubscriber = this->create_subscription<std_msgs::msg::Float64MultiArray>(topic_name, 10, callback);
}

void RosTopicManager::spinNode()
{
    std::thread([this]() {
        rclcpp::spin(this->get_node_base_interface());
    }).detach();
}