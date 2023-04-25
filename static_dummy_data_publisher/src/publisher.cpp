#include "ros/ros.h"  //包含ROS中常用的头文件
#include "std_msgs/String.h" //按照ros命名规则，std_msgs/String是在ros目录下的string文件内，该文件中有一个string.msg文件
#include <sstream>
 
//初始化ROS系统
//广播消息：在chatter主题上发布std_msgs/String消息到节点管理器
//以指定的频率循环发布消息到chatter
 
int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");//初始化一个ros节点，节点名称必须是唯一的
    //创建用于处理该节点的句柄，这是一个类，开始是见初始化节点，结束时最后用析构函数清除所用资源
    ros::NodeHandle n;
    //创建一个发布主题
    //节点管理器把chatter主题上发布的数据告知正在监听这个主题的节点
    //NodeHandle::advertise()返回一个ros::publisher()方法，让用户可以在创建的主题上发布消息
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);//"chattet"发布的主题  1000 发布队列的长度
    //指定循环频率10hz，它追踪上一次Rate::sleep()被唤醒之后持续的时间，并在到达指定时间后休眠
    ros::Rate loop_rate(10);
    int count = 0;
    //在缺省情况下，roscpp安装一个句柄，当系统按下ctrl+c时，ros::ok()返回flase
    while(ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello word!!" <<count;
        //C++标准流控制，把字符流给mag.data
        msg.data = ss.str();
        //类似与printf和cout
        ROS_INFO("%s", msg.data.c_str());
        //创建主题时返回的句柄，提供发布消息的方法，用于发布数据
        chatter_pub.publish(msg);
        //
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}
