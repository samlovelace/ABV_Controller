#ifndef ROSTOPICMANAGER_H   
#define ROSTOPICMANAGER_H

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class RosTopicManager : public rclcpp::Node
{

public:
    RosTopicManager(/* args */);
    ~RosTopicManager();

    void init();
    void publish(std::string aMsg);

    void modeCallback(const std_msgs::msg::String::SharedPtr msg);

    void createSubscriber(const std::string& topic_name,
                          std::function<void(const std_msgs::msg::String::SharedPtr)> callback);

    bool isROSInitialized() { return rclcpp::ok(); }

private:

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr mModeSubscriber;
};

#endif
