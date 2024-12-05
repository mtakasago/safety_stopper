#include "safety_stopper/safety_stopper.hpp"

SafetyStopper::SafetyStopper():Node("safety_stopper_node")
{
    //param
    stop_dist_ = this->declare_parameter<float>("stop_dist", 1.0); // m

    //publisher
    pub_stop_signal_ = this->create_publisher<std_msgs::msg::Bool>("/emergency_stop", rclcpp::QoS(1).reliable());

    //subscriber
    sub_laser_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "scan",
            rclcpp::QoS(1).reliable(),
            std::bind(&SafetyStopper::laser_callback,this,std::placeholders::_1));
}

void SafetyStopper::laser_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
{
    auto flag = std_msgs::msg::Bool();
    for(auto& range : msg->ranges)
    {
        if(msg->range_min < range && range <= stop_dist_)
        {
            flag.data = 1;
            std::cout<<"!!!!! SAFETY STOP !!!!!"<<std::endl;
            break;
        }
    }
    pub_stop_signal_->publish(flag);
}
int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    SafetyStopper safety_stopper;
    auto node = std::make_shared<SafetyStopper>();
    rclcpp::spin(node);
    rcl::shutdown();
    return 0;
}
