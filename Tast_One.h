
#include<iostream>
#include"opencv2/opencv.hpp"
#include<time.h>
#include <stdlib.h>
#include<cmath>

using namespace std;
using namespace cv;

#define ROI_BIG 3000

#define POINT_NUMBER 50

#define MAX_VAL 2.0*pow(10,7)

void on_track(int ,void*);

class Tast_one
{
public:

    Mat src,dst,ds;
    Mat greed_right;
    Mat ROI;
    Mat ROI_1;
    Mat ROI_2;

    Rect zxc;
    int value_min,value_max;
    clock_t start,finish;
    bool conclusion;


    void initial();
    void Image_preprocessing();
    void Task_one();
    double getDistance(Point A,Point B);
    void on_track(int ,void*);

    double macth_green();
    int point_macth();
    bool analysis(Rect&num,double&maxVal,int&Point_count);
    int doing();
    void Frame_rate();
};