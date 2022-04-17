#include <stdio.h>     /*标准输入输出定义*/
#include <stdlib.h>    /*标准函数库定义*/
#include <unistd.h>    /*Unix 标准函数定义*/
#include <sys/types.h> /*数据类型，比如一些XXX_t的那种*/
#include <sys/stat.h>  /*定义了一些返回值的结构，没看明白*/
#include <fcntl.h>     /*文件控制定义*/
#include <termios.h>   /*PPSIX 终端控制定义*/
#include <errno.h>     /*错误号定义*/
#include <iostream>
using namespace std;

    
class Serial
{
    
    public:
    //串口状态变量
    int fd = -1;
    //比特率配置
    int speed_arr[15] = { B38400, B19200, B9600, B4800, B2400, B1200, B300,
                  B38400, B19200, B9600, B4800, B2400, B1200, B300, B115200 };

    int name_arr[15] = {38400,  19200,  9600,  4800,  2400,  1200,  300, 38400, 
                  19200,  9600, 4800, 2400, 1200,  300,115200 };



    //打开串口
    void open_port();
    void set_speed(int fd, int speed);
    void write_port(char buffer);
    int read_port(char import[48]);
    ~Serial();
};