#include"Ser.h"

//打开串口
void Serial::open_port()
{
    /*以读写方式打开串口*/
    cout<<"正在打开串口"<<endl;
    fd = open("/dev/ttyUSB0", O_RDWR);
    if (-1 == fd)
    {
        /* 不能打开串口一*/
        perror(" 串口打开失败！");
        cout<<"打开串口失败"<<endl;
    }
    else
    {
        cout << "串口打开成功！" << endl;
    }
}

//设置比特率速度
void Serial::set_speed(int fd, int speed)
{
    int status;
    //定义结构体
    struct termios Opt;
    //fd=0标准输入，该函数作用是将fd的状态放入结构体
    tcgetattr(fd, &Opt);
    //使用原始模式
    //Opt.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); /*Input*/
    //Opt.c_oflag &= ~OPOST; /*Output*/

    for (int i = 0; i < sizeof(speed_arr) / sizeof(int); i++)
    {

        if (speed == name_arr[i])
        {
            tcflush(fd, TCIOFLUSH);
            cfsetispeed(&Opt, speed_arr[i]);
            cfsetospeed(&Opt, speed_arr[i]);
            status = tcsetattr(fd, TCSANOW, &Opt);
            if (status != 0)
            {
                perror("tcsetattr fd1");
                return;
            }
            else{
                cout<<"比特率速度修改成功"<<endl;
            }
            tcflush(fd, TCIOFLUSH); 
        }
    }
}

void Serial::write_port(char buffer)
{
    
    int Length = 1;
    int nByte;

    nByte = write(fd, &buffer ,Length);
    //cout<<"nByte="<<nByte<<endl;
    //cout<<"Length="<<Length<<endl;

}

int Serial::read_port(char import[48])
{
    
    int nread =read(fd,import, 48);
    cout<<"nread:"<<nread<<endl;
    cout<<"buffer:"<<import<<endl;
    return nread;
}
Serial::~Serial()
{
    close(fd);
}