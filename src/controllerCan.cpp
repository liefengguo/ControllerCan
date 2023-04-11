#include "ros/ros.h"
#include "ecar.h"
// #include "decision.h"
#include "decision.pb.h"
#include "can_msgs/Frame.h"
#include <thread>
#include <chrono>
#include "geometry_msgs/Twist.h"
#include <autoware_msgs/VehicleCmd.h>
#include <boost/algorithm/clamp.hpp>

#include<mutex>
ros::Publisher canmsg_pub;
std::mutex gMutex;
int CtrlActive = 0;
// uint8_t CtrlActive = 0;
const double max_acc = 3.5;
const double max_dec = 7.0;
const double max_steering_angle = 34.0;
double LongtdnalSpd;
const double vel_l = 2.1; //vel len
uint64_t * byte_118 = (uint64_t*) malloc(sizeof(uint64_t));
uint64_t * byte_119=(uint64_t*) malloc(sizeof(uint64_t));
uint64_t * byte_11a=(uint64_t*) malloc(sizeof(uint64_t));
uint64_t * byte_111=(uint64_t*) malloc(sizeof(uint64_t));
uint64_t * byte_112=(uint64_t*) malloc(sizeof(uint64_t));
uint64_t * byte_113=(uint64_t*) malloc(sizeof(uint64_t));
uint64_t * byte_114=(uint64_t*) malloc(sizeof(uint64_t));

CldDrv_118_t _m118 ={0};
CldBoby_119_t _m119 ={0};
CldPower_11a_t _m11a ={0};
can_msgs::Frame frame118;
can_msgs::Frame frame119;
can_msgs::Frame frame11a;
can_msgs::Frame frame215;
can_msgs::Frame frame217;
can_msgs::Frame frame250;
can_msgs::Frame frame251;
can_msgs::Frame frame111;
can_msgs::Frame frame112;
can_msgs::Frame frame113;
can_msgs::Frame frame114;

can_0x111_ADCU_BrakeCmd_t _m111 ={0};
can_0x112_ADCU_ParkCmd_t _m112 ={0};
can_0x113_ADCU_SteerCmd_t _m113 ={0};
can_0x114_ADCU_DriveCmd0_t _m114 ={0};
can_0x215_CDCU_SteerStatus_t _m215 ={0};
can_0x217_CDCU_DriveStatus_t _m217 ={0};
can_0x250_CDCU_VehDyncState_t _m250 ={0};
can_0x251_CDCU_VehFtWhlSpd_t _m251 ={0};
can_0x252_CDCU_VehRrWhlSpd_t _m252 ={0};
Decision gdecision ;
double throtVal_key ;
double brkVal_key;
double angle_key ;
void executeDecition(Decision decision){

    // encode_can_0x118_ADCU_Cld_CtrlActive(&_m118,CtrlActive);

    // encode_can_0x118_ADCU_Cld_PrkEnable(&_m118,0);
    // encode_can_0x118_ADCU_Cld_TgtGear(&_m118,decision.getTgtGear());
    // encode_can_0x118_ADCU_Cld_TgtThrotVal(&_m118,decision.getThrotVal());
    // encode_can_0x118_ADCU_CldDrvCmd_RollCnt(&_m118,0);
    // encode_can_0x118_ADCU_Cld_TgtBrkVal(&_m118,decision.getBrkVal());
    // encode_can_0x118_ADCU_Cld_TgtStrAngle(&_m118,decision.getAngle());
    // encode_can_0x118_ADCU_CldDrvCmd_RollCnt(&_m118,0);
    encode_can_0x111_ADCU_Brk_TgtPress(&_m111,decision.brk_tgtpress());
    encode_can_0x111_ADCU_Brk_TgtAccSpd(&_m111,decision.brk_tgtaccspd());
    encode_can_0x111_ADCU_Brk_TgtPedpos(&_m111,decision.brk_tgtpedpos());
    encode_can_0x111_ADCU_BrkCmd_RollCnt(&_m111,0);
    encode_can_0x111_ADCU_Brk_CtrlMode(&_m111,decision.brk_ctrlmode());
    encode_can_0x111_ADCU_Brk_Active(&_m111,CtrlActive);

    encode_can_0x112_ADCU_PrkCmd_RollCnt(&_m112,5);
    encode_can_0x112_ADCU_Prk_Enable(&_m112,decision.prk_enable());
    encode_can_0x112_ADCU_Prk_Active(&_m112,CtrlActive);

    encode_can_0x113_ADCU_Str_TgtAngle(&_m113,decision.str_tgtangle());
    encode_can_0x113_ADCU_Str_TgtCurvature(&_m113,decision.str_tgtcurvature());
    encode_can_0x113_ADCU_Str_TgtAngleSpd(&_m113,decision.str_tgtanglespd());
    encode_can_0x113_ADCU_StrCmd_RollCnt(&_m113,6);
    encode_can_0x113_ADCU_Str_CtrlMode(&_m113,decision.str_ctrlmode());
    encode_can_0x113_ADCU_Str_Active(&_m113,CtrlActive);

    encode_can_0x114_ADCU_Drv_TgtVehSpd0(&_m114,decision.drv_tgtvehspd0());
    encode_can_0x114_ADCU_Drv_TgtPedpos(&_m114,decision.drv_tgtpedpos());
    encode_can_0x114_ADCU_Drv_TgtVehAccSpd(&_m114,decision.drv_tgtvehaccspd());
    encode_can_0x114_ADCU_Drv_VehSpdLimit(&_m114,decision.drv_vehspdlimit());
    encode_can_0x114_ADCU_DrvCmd_RollCnt(&_m114,7);
    encode_can_0x114_ADCU_Drv_TgtGear(&_m114,decision.drv_tgtgear());
    encode_can_0x114_ADCU_Drv_CtrlMode(&_m114,decision.drv_ctrlmode());
    encode_can_0x114_ADCU_Drv_Active(&_m114,CtrlActive);
    


    encode_can_0x119_ADCU_Cld_WidthLamp_Cmd(&_m119,0);
    encode_can_0x119_ADCU_Cld_BrkLamp_Cmd(&_m119,0);
    encode_can_0x119_ADCU_Cld_FogLamp_Cmd(&_m119,0);
    encode_can_0x119_ADCU_Cld_HeadLamp_Cmd(&_m119,0);
    encode_can_0x119_ADCU_Cld_DblFlashLamp_Cmd(&_m119,0);
    encode_can_0x119_ADCU_Cld_TurnLLamp_Cmd(&_m119,0);
    encode_can_0x119_ADCU_Cld_TurnRLamp_Cmd(&_m119,0);
    encode_can_0x119_ADCU_Cld_BackLamp_Cmd(&_m119,0);
    encode_can_0x119_ADCU_Cld_Buzzer_Cmd(&_m119,0);
    encode_can_0x119_ADCU_Cld_Horn_Cmd(&_m119,0);
    encode_can_0x119_ADCU_Cld_RunLamp_Cmd(&_m119,0);
    encode_can_0x119_ADCU_CldBodyCmd_RollCnt(&_m119,1);

    encode_can_0x11a_ADCU_CldVehPwrup_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_CldChasPwrup_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_Cld12VMCPwrup_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_Cld12VRCPwrup_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_Cld24VMCPwrup_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_CldPA12VPwrup_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_CldPA24VPwrup_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_Cld12VSC1Pwrup_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_Cld12VSC2Pwrup_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_Cld12VSC3Pwrup_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_Cld12VMCPwrdownCnfm_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_Cld12VRCPwrdownCnfm_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_Cld24VMCPwrdownCnfm_Cmd(&_m11a,0);
    encode_can_0x11a_ADCU_CldPwrCmd_RollCnt(&_m11a,2);

    // pack_can_0x118_ADCU_CldDrvCmd(&_m118,byte_118);
    pack_can_0x119_ADCU_CldBodyCmd(&_m119, byte_119);
    pack_can_0x11a_ADCU_CldPowerCmd(&_m11a, byte_11a);
    pack_can_0x111_ADCU_BrakeCmd(&_m111, byte_111);
    pack_can_0x112_ADCU_ParkCmd(&_m112, byte_112);
    pack_can_0x113_ADCU_SteerCmd(&_m113, byte_113);
    pack_can_0x114_ADCU_DriveCmd0(&_m114, byte_114);
    uint8_t check118 = checksum(byte_118);
    uint8_t check119 = checksum(byte_119);
    uint8_t check11a = checksum(byte_11a);
    uint8_t check111 = checksum(byte_111);
    uint8_t check112 = checksum(byte_112);
    uint8_t check113 = checksum(byte_113);
    uint8_t check114 = checksum(byte_114);
    // encode_can_0x118_ADCU_CldDrvCmd_Checksum(&_m118,check118);
    encode_can_0x119_ADCU_CldBodyCmd_Checksum(&_m119,check119);
    encode_can_0x11a_ADCU_CldPwrCmd_Checksum(&_m11a,check11a);
    encode_can_0x111_ADCU_BrkCmd_Checksum(&_m111,check111);
    encode_can_0x112_ADCU_PrkCmd_Checksum(&_m112,check112);
    encode_can_0x113_ADCU_StrCmd_Checksum(&_m113,check113);
    encode_can_0x114_ADCU_DrvCmd_Checksum(&_m114,check114);

    // pack_can_0x118_ADCU_CldDrvCmd(&_m118,byte_118);
    pack_can_0x119_ADCU_CldBodyCmd(&_m119, byte_119);
    pack_can_0x11a_ADCU_CldPowerCmd(&_m11a, byte_11a);
    pack_can_0x111_ADCU_BrakeCmd(&_m111, byte_111);
    pack_can_0x112_ADCU_ParkCmd(&_m112, byte_112);
    pack_can_0x113_ADCU_SteerCmd(&_m113, byte_113);
    pack_can_0x114_ADCU_DriveCmd0(&_m114, byte_114);
}

void ExecSend(){
    // frame118.header.frame_id = "";  // empty frame is the de-facto standard for no frame.
    // frame118.header.stamp = ros::Time::now();
    // frame118.id = 0x118;
    // //   frame118.data = byte_118;
    // memcpy(frame118.data.data(), byte_118, sizeof(uint64_t));
    // // memcpy( frame118.data.data(), reinterpret_cast<unsigned char*>(byte_118), sizeof(uint64_t));
    // frame118.is_rtr = false;
    // frame118.is_error = false;
    // frame118.is_extended = false;
    // frame118.dlc = 8;

    frame111.header.frame_id = "";  // empty frame is the de-facto standard for no frame.
    frame111.header.stamp = ros::Time::now();
    frame111.id = 0x111;
    //   frame118.data = byte_118;
    memcpy(frame111.data.data(), byte_111, sizeof(uint64_t));
    // memcpy( frame118.data.data(), reinterpret_cast<unsigned char*>(byte_118), sizeof(uint64_t));
    frame111.is_rtr = false;
    frame111.is_error = false;
    frame111.is_extended = false;
    frame111.dlc = 8;

    frame112.header.frame_id = "";  // empty frame is the de-facto standard for no frame.
    frame112.header.stamp = ros::Time::now();
    frame112.id = 0x112;
    //   frame118.data = byte_118;
    memcpy(frame112.data.data(), byte_112, sizeof(uint64_t));
    // memcpy( frame118.data.data(), reinterpret_cast<unsigned char*>(byte_118), sizeof(uint64_t));
    frame112.is_rtr = false;
    frame112.is_error = false;
    frame112.is_extended = false;
    frame112.dlc = 8;


    frame113.header.frame_id = "";  // empty frame is the de-facto standard for no frame.
    frame113.header.stamp = ros::Time::now();
    frame113.id = 0x113;
    //   frame118.data = byte_118;
    memcpy(frame113.data.data(), byte_113, sizeof(uint64_t));
    // memcpy( frame118.data.data(), reinterpret_cast<unsigned char*>(byte_118), sizeof(uint64_t));
    frame113.is_rtr = false;
    frame113.is_error = false;
    frame113.is_extended = false;
    frame113.dlc = 8;

    
    frame114.header.frame_id = "";  // empty frame is the de-facto standard for no frame.
    frame114.header.stamp = ros::Time::now();
    frame114.id = 0x114;
    //   frame118.data = byte_118;
    memcpy(frame114.data.data(), byte_114, sizeof(uint64_t));
    // memcpy( frame118.data.data(), reinterpret_cast<unsigned char*>(byte_118), sizeof(uint64_t));
    frame114.is_rtr = false;
    frame114.is_error = false;
    frame114.is_extended = false;
    frame114.dlc = 8;


    frame119.header.frame_id = "";  // empty frame is the de-facto standard for no frame.
    frame119.header.stamp = ros::Time::now();
    frame119.id = 0x115;
    memcpy(frame119.data.data(), byte_119, sizeof(uint64_t));
    frame119.is_rtr = false;
    frame119.is_error = false;
    frame119.is_extended = false;
    frame119.dlc = 8;

    frame11a.header.frame_id = "";  // empty frame is the de-facto standard for no frame.
    frame11a.header.stamp = ros::Time::now();
    frame11a.id = 0x117;
    memcpy(frame11a.data.data(), byte_11a, sizeof(uint64_t));
    frame11a.is_rtr = false;
    frame11a.is_error = false;
    frame11a.is_extended = false;
    frame11a.dlc = 8;
    canmsg_pub.publish(frame111);
    canmsg_pub.publish(frame112);
    canmsg_pub.publish(frame113);
    canmsg_pub.publish(frame114);
    canmsg_pub.publish(frame119);
    canmsg_pub.publish(frame11a);

}
void UnActivate(){
    for(int i = 0; i < 18; i++){
        CtrlActive = 0;
        executeDecition(gdecision);
        ExecSend();
        std::cout<<"i:"<<i<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

}
int state_activate = 0;
void Activate(){
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    if (state_activate < 50){
        for(int i = 0; i < 55; i++){
            state_activate++;
            CtrlActive = 0;
            executeDecition(gdecision);
            ExecSend();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    for(int i = 0; i < 10; i++){
        CtrlActive = 1;
        executeDecition(gdecision);
        ExecSend();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

// void sendthread(){
//     UnActivate();
//     while(ros::ok){
//     Activate();
//     executeDecition(gdecision);
//     ExecSend();
//     std::this_thread::sleep_for(std::chrono::milliseconds(10));
//     }
// }
// void keyboardCallback(const geometry_msgs::Twist& msg) {
//     uint8_t ctrlActive_key = 1;
//     throtVal_key += msg.linear.x  ;
//     brkVal_key += msg.linear.y * 66 ;
//     angle_key += msg.angular.z *6;
//     // angle_key += static_cast<uint16_t>((msg.angular.z / 0.1) + 32768);
//     // angle_key %= 65536;
//     std::cout<<"throtVal_key:"<<throtVal_key<<"msg.linear.x:"<<msg.linear.x<<std::endl;
//     // std::cout<<"brkVal_key:"<<brkVal_key<<"msg.linear.y:"<<msg.linear.y<<std::endl;
//     std::cout<<"angle_key:"<<angle_key<<"msg.angular.z:"<<msg.angular.z<<std::endl;
//     // gdecision.copyFrom(Decision{ctrlActive_key, 1,throtVal_key, brkVal_key, angle_key});
//     Activate();
//     executeDecition(gdecision);
//     ExecSend();
// }
void get_car_state(const can_msgs::Frame& msg){
    std::cout<<"come on!!!!"<<std::endl;
    if(msg.id == 0x215) {
        double StrWhlAngle;
        double WhlSpd;
        double StrTrq;
        uint64_t  byte_215 = (uint64_t) malloc(sizeof(uint64_t));
        memcpy(&byte_215, msg.data.data(), sizeof(uint64_t));
        unpack_can_0x215_CDCU_SteerStatus(&_m215,byte_215,msg.dlc);
        decode_can_0x215_CDCU_EPS_StrWhlAngle(&_m215,&StrWhlAngle);
        decode_can_0x215_CDCU_EPS_WhlSpd(&_m215,&WhlSpd);
        decode_can_0x215_CDCU_EPS_StrTrq(&_m215,&StrTrq);
        std::cout<<"StrWhlAngle:"<<StrWhlAngle<<std::endl;
    }
    if(msg.id == 0x250) {
        double LongtdnalAccSpd;
        // double LongtdnalSpd;
        double Curvture;
        uint8_t RunDir;
        uint64_t  byte_250 = (uint64_t) malloc(sizeof(uint64_t));
        memcpy(&byte_250, msg.data.data(), sizeof(uint64_t));
        unpack_can_0x250_CDCU_VehDyncState(&_m250,byte_250,msg.dlc);
        decode_can_0x250_CDCU_Veh_LongtdnalAccSpd(&_m250,&LongtdnalAccSpd);
        decode_can_0x250_CDCU_Veh_LongtdnalSpd(&_m250,&LongtdnalSpd);
        decode_can_0x250_CDCU_Veh_Curvture(&_m250,&Curvture);
        decode_can_0x250_CDCU_Veh_RunDir(&_m250,&RunDir);
        std::cout<<"LongtdnalAccSpd"<<LongtdnalAccSpd<<std::endl;
    }
    if(msg.id == 0x251) {
        double LfFtWhlSpd;
        double RtFtWhlSpd;
        uint64_t  byte_251 = (uint64_t) malloc(sizeof(uint64_t));
        memcpy(&byte_251, msg.data.data(), sizeof(uint64_t));
        unpack_can_0x251_CDCU_VehFtWhlSpd(&_m251,byte_251,msg.dlc);
        decode_can_0x251_CDCU_Veh_LfFtWhlSpd(&_m251,&LfFtWhlSpd);
        decode_can_0x251_CDCU_Veh_RtFtWhlSpd(&_m251,&RtFtWhlSpd);
        std::cout<<"RtFtWhlSpd"<<RtFtWhlSpd<<std::endl;
    }
}
void ctrlrawCallback(const autoware_msgs::VehicleCmd::ConstPtr& vehicle_cmd_msg)
{
    // double linear_velocity = vehicle_cmd_msg->twist_cmd.twist.linear.x;
    // double angular_velocity = vehicle_cmd_msg->twist_cmd.twist.angular.z;

    // // 计算加速度
    // double acceleration = linear_velocity * angular_velocity;

    // double throttle = 0.0;
    // double brake = 0.0;

    // if (acceleration >= 0)
    // {
    // throttle = std::min(acceleration / max_acc, 1.0);
    // }
    // else
    // {
    // brake = std::min(fabs(acceleration) / max_dec, 1.0);
    // }
    // // 计算方向盘转角
    // double steering_angle = atan(angular_velocity * 2.7 / linear_velocity) * 180 / M_PI;
    // // 将方向盘转角限制在车辆最大转角范围内
    // steering_angle = std::min(std::max(steering_angle, -max_steering_angle), max_steering_angle);
    // double delta = atan(vel_l * vehicle_cmd_msg->steer_cmd.steer / (LongtdnalSpd * cos(vehicle_cmd_msg->steer_cmd.steer)));
    // double omega = LongtdnalSpd * tan(vehicle_cmd_msg->steer_cmd.steer) / vel_l;
    double speed_ms = vehicle_cmd_msg->twist_cmd.twist.linear.x;
    double omega = vehicle_cmd_msg->twist_cmd.twist.angular.z;
    double in_steer_degree = atan((omega/speed_ms)*vel_l) * 180/M_PI;
    double  speed_value = (speed_ms * 3.6);
    speed_value =  std::min(speed_value, 3.0);// max_value = 3 km/h
    double steer_degree = boost::algorithm::clamp(in_steer_degree,-30.3,30.3); 
    Decision xdecision;
    xdecision.set_brk_ctrlmode(2); // choese speed mode
    xdecision.set_brk_tgtaccspd(vehicle_cmd_msg->brake_cmd.brake);
    xdecision.set_str_ctrlmode(0);  //choese angle control mode
    xdecision.set_str_tgtangle(steer_degree);
    xdecision.set_str_tgtanglespd(vehicle_cmd_msg->twist_cmd.twist.angular.z);
    xdecision.set_drv_ctrlmode(1);  // choese speed control
    xdecision.set_drv_tgtgear(vehicle_cmd_msg->gear_cmd.gear);
    xdecision.set_drv_tgtpedpos(vehicle_cmd_msg->ctrl_cmd.linear_acceleration/100.0);
    xdecision.set_drv_tgtvehaccspd(vehicle_cmd_msg->accel_cmd.accel);
    xdecision.set_drv_tgtvehspd0(speed_value);
    xdecision.set_drv_vehspdlimit(10);// speed limit 10km/h
    xdecision.set_prk_enable(vehicle_cmd_msg->gear_cmd.gear == autoware_msgs::Gear::PARK);
    xdecision.set_drv_active(1);
    gMutex.lock();
    gdecision.CopyFrom(xdecision);
    gMutex.unlock();
    Activate();
    executeDecition(gdecision);
    ExecSend();

}
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"controllerCan");
    ros::NodeHandle n;
    ros::Rate loop_rate(100);
    canmsg_pub = n.advertise<can_msgs::Frame>("sent_messages",10);
    // std::thread xthread(sendthread);
    // ros::Subscriber sub = n.subscribe("keyboard_twist", 10, keyboardCallback);
    // ros::Subscriber sub_received_msg = n.subscribe("received_messages", 10, get_car_state);
    ros::Subscriber ctrlcmd_sub = n.subscribe("autoware_msgs/VehicleCmd", 1, ctrlrawCallback);
    // xthread.join();
    ros::Rate(20);
    ros::spin();
    return 0;
}
