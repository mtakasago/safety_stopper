#ifndef SAFETY_STOPPER_HPP
#define SAFETY_STOPPER_HPP

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <std_msgs/msg/bool.hpp>

class SafetyStopper: public rclcpp::Node
{
    public:
        SafetyStopper();

    private:
        // function
        void laser_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg);

        // param
        float stop_dist_;

        //subscriber
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr sub_laser_;
        //publisher
        rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr pub_stop_signal_;
};
#endif
