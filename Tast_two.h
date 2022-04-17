
#include<iostream>
#include"opencv2/opencv.hpp"
#include<time.h>
#include <stdlib.h>



using namespace std;
using namespace cv;


#define MAX_NUMBER_TWO 10

#define ROI_BIG_TWO 1000

#define MAX_VAL_TWO 5.0*pow(10,6)



class Tast_Two
{
public:

    Mat src,dst,ds,src1,dst1,Dsrc,WKJ_TAST,WKJ_TAST2;
    Mat ima,sr,sr1;
    Mat I;
    Mat ROI,ROI_2,ROI_3;
    int value_min,value_max;
    Rect num;
    Rect zxc;
    int structElementSize[3] = {1,0,10};
    Mat element[3];
    Mat ROI_[4];
    clock_t start,finish;
    int b_val;
    int asd;
    int thre;
    int thre_max;
    int ok;

    void initial();
    void Image_preprocessing();
    void Task_two();
    void cvHilditchThin1(cv::Mat& src, cv::Mat& dst);
    double macth_green();

    void Frame_rate();
    int doing();



};