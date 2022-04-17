

#include<iostream>
#include"Tast_two.h"
#include"Ser.h"
#include"Tast_One.h"
#include<string.h>


using namespace std;

int main()
{

    char select[48]={"\0"}; 
    char select1[48]={"\0"}; 
    char select2[48]={"\0"}; 
    
    Serial serial;
    serial.open_port();
    serial.set_speed(serial.fd,115200);
    int num_race = -1;
    Tast_one one;
    Tast_Two two;
    bool qwert = false;

    while(1)
    {
        cout<<"等待"<<endl;
        select[0] = '\0';
        int ddl = serial.read_port(select);
        
        if(ddl == -1)
            return -1;
        
        for(int i = 0;i < 24 ; i++)
        {
            if(select[0] == 'x')
            {
                cout<<"识别开始"<<endl;
                one.doing();
                serial.write_port('G');
                cout<<"绿灯"<<endl;
                break;
            }
            else if(select[0] == 'c')
            {
                cout<<"开始识别"<<endl;
                int DADA = two.doing();
                //waitKey(2000);
                if(DADA==1)
                {
                    serial.write_port('W');
                }
                else if(DADA==2)
                {
                    serial.write_port('A');
                }
                else if(DADA==3)
                {
                    serial.write_port('D');
                }
                break;
            }
            else if(select[0] == 'v')
            {
                cout<<"开始识别"<<endl;
                int DADA = two.doing();
                //waitKey(2000);
                if(DADA==1)
                {
                    serial.write_port('W');
                }
                else if(DADA==2)
                {
                    serial.write_port('A');
                }
                else if(DADA==3)
                {
                    serial.write_port('D');
                }
                break;
            }
            else if(select[0] == 'p')
            {

            }

        }
        
    }

    // while(1)
    // {
    //     select[0] = '\0';
    //     select1[0] = '\0';
    //     select2[0] = '\0';
    //     qwert = false;
    //     while(num_race<0)
    //     { 
    //         cout<<"起跑线位置：："<<endl;
    //         int ddl = serial.read_port(select);
    //         if(ddl == -1)
    //             return -1;
    //         for(int i=0;i<24;i++)
    //         {
    //             if(select[i] == 'x')
    //             {
    //                 num_race++;
    //                 break;
    //             }
    //             else if(select[i]=='p')
    //             {
    //                 num_race++;
    //                 qwert = true;
    //                 break;
    //             }
    //                 else if(select[i]=='y')
    //             {
    //                 return -1;
    //             }
    //         }
    //         //waitKey(1000);
    //     }
    //     if(qwert)
    //     {
    //         num_race = -1;
    //         cout<<"wnd"<<endl;
    //         qwert = false;
    //         continue;

    //     }
    //     if(!num_race)
    //     {
    //         cout<<"识别开始"<<endl;
    //         one.doing();
    //         cout<<"绿灯"<<endl;
    //         //waitKey(2000);
    //         serial.write_port('G');
            
            
    //         cout<<"o"<<endl;
    //     }
    //     while(num_race==0)
    //     {
    //         cout<<"第一个十字路口位置：："<<endl;
    //         serial.read_port(select1);
            
    //         for(int i=0;i<24;i++)
    //         {
    //             if(select1[i] == 'c')
    //             {
    //                 num_race++;
    //                 break;
    //             }
    //             else if(select1[i]=='p')
    //             {
    //                 num_race++;
    //                 qwert = true;
    //                 break;
    //             }
    //             else if(select1[i]=='y')
    //             {
    //                 return -1;
    //             }
    //         }
        
    //         //waitKey(1000);

    //     }
    //     if(qwert)
    //     {
    //         num_race = -1;
    //         continue;
    //     }
    //     if(num_race==1)
    //     {
    //         int DADA=1;
    //         cout<<"识别开始"<<endl;
    //         DADA = two.doing();
    //         //waitKey(2000);
    //         if(DADA==1)
    //         {
    //             serial.write_port('W');
    //         }
    //         else if(DADA==2)
    //         {
    //             serial.write_port('A');
    //         }
    //         else if(DADA==3)
    //         {
    //             serial.write_port('D');
    //         }

    //     }
    //     while(num_race==1)
    //     {
    //         cout<<"第二个十字路口位置：："<<endl;
    //         serial.read_port(select2);
            
    //         for(int i=0;i<24;i++)
    //         {
    //             if(select2[i] == 'v')
    //             {
    //                 num_race++;
    //                 break;
    //             }
    //             else if(select2[i]=='p')
    //             {
    //                num_race++;
    //                 qwert = true;
    //                 break;
    //             }
    //             else if(select2[i]=='y')
    //             {
    //                 return -1;
    //             }
    //         }
    //     }
    //     if(qwert)
    //     {
    //         num_race = -1;
    //         continue;
    //     }
    //     if(num_race==2)
    //     {
    //         int DADA=2;
    //         cout<<"识别开始"<<endl;
    //         DADA = two.doing();
    //         //waitKey(2000);
    //         if(DADA==1)
    //         {
    //             serial.write_port('W');
    //         }
    //         else if(DADA==2)
    //         {
    //             serial.write_port('A');
    //         }
    //         else if(DADA==3)
    //         {
    //             serial.write_port('D');
    //         }
    //     }
    //     cout<<"完成任务"<<endl; 
    //     num_race = -1;
    //     qwert = false;

    // }

    //one.doing();
    //two.doing();
    return 0;
}