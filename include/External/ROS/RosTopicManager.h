#ifndef ROSTOPICMANAGER_H   
#define ROSTOPICMANAGER_H

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>

class RosTopicManager : public rclcpp::Node
{

public:
    RosTopicManager(/* args */);
    ~RosTopicManager();

    void init();
    void publish(std::string aMsg);

    void modeCallback(const std_msgs::msg::String::SharedPtr msg);

    void createModeSubscriber(const std::string& topic_name,
                          std::function<void(const std_msgs::msg::String::SharedPtr)> callback);

    void createInputSubscriber(const std::string& topic_name,
                          std::function<void(const std_msgs::msg::Float64MultiArray::SharedPtr)> callback);

    template<typename T>
    void createPublisher(const std::string& topicName) 
    {
        auto publisher = this->create_publisher<T>(topicName, 10);
        mPublishers[topicName] = std::dynamic_pointer_cast<rclcpp::PublisherBase>(publisher);
    }

    template<typename T>
    void publishMessage(const std::string& topicName, const T& message) 
    {
        auto it = mPublishers.find(topicName);
        
        if (it != mPublishers.end()) 
        {
            // Cast PublisherBase back to Publisher<T>
            auto pub = std::dynamic_pointer_cast<rclcpp::Publisher<T>>(it->second);
            if (pub) 
            {
                pub->publish(message);
            } 
            else 
            {
                RCLCPP_ERROR(this->get_logger(), "Failed to cast publisher for topic: %s", topicName.c_str());
            }
        } 
        else 
        {
            RCLCPP_ERROR(this->get_logger(), "Publisher not found for topic: %s", topicName.c_str());
        }
    }

    void spinNode();

    bool isROSInitialized() { return rclcpp::ok(); }

private:

    std::map<std::string, rclcpp::PublisherBase::SharedPtr> mPublishers;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr mModeSubscriber;
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr mInputSubscriber;
};

#endif
