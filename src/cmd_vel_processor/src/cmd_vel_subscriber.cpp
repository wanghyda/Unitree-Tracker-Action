#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <unitree/robot/g1/loco/g1_loco_client.hpp>
#include <unitree/robot/g1/loco/g1_loco_api.hpp>


class CmdVelSubscriber : public rclcpp::Node
{
public:
    CmdVelSubscriber()
    : Node("cmd_vel_subscriber")
    {
        unitree::robot::ChannelFactory::Instance()->Init(0,"eth0");
        
        client = std::make_unique<unitree::robot::g1::LocoClient>();
        client->Init();
        client->SetTimeout(10.f);
        int a=client->Start();
        RCLCPP_INFO(this->get_logger(), "client init %d",a);
        // a=client->SetFsmId(500);
        // RCLCPP_INFO(this->get_logger(), "mode set :Move.%d",a);
        client->GetFsmId(a);
        RCLCPP_INFO(this->get_logger(), "client mode: %d",a);
        // 订阅 /cmd_vel 话题
        subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10,
            std::bind(&CmdVelSubscriber::topic_callback, this, std::placeholders::_1));
    }
     ~CmdVelSubscriber() {
    //  析构时发送停止命令
        client->StopMove();
    }

private:
    void topic_callback(const geometry_msgs::msg::Twist::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(), "Received cmd_vel: linear x=%.2f, angular z=%.2f",
                    msg->linear.x, msg->angular.z);
        int b=client->Move(msg->linear.x,msg->linear.y, msg->angular.z);
        RCLCPP_INFO(this->get_logger(), "Start moving %d",b);
        // 在这里进行处理，比如转换成串口字节流、控制电机等
    }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
    std::unique_ptr<unitree::robot::g1::LocoClient> client;

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CmdVelSubscriber>());
    rclcpp::shutdown();
    return 0;
}
