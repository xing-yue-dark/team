#include "Tast_One.h"

void Tast_one::initial()
{
    cout<<"绿灯开始"<<endl;
    conclusion = false;
    value_min = 30;
    value_max = 100;
    greed_right = imread("/home/pi/Desktop/code_S/mmexport1645623841686.jpg");

}
void Tast_one::Image_preprocessing()
{
     //分离通道参数
    vector<Mat>image;
    split(src,image);
    //绿蓝通道相减得出绿灯的二值化图像
    dst = image[1] - image[0];
    //imshow("4",dst);

    //加深图像色差
    threshold(dst,dst,50,255,THRESH_BINARY);
    //imshow("5",dst);
    //waitKey(0);
    
    //避免灯光导致屏幕反光而造成误差
    Mat Element;
    Element = getStructuringElement(MORPH_RECT,Size(value_min+1,value_min+1));
    dilate(dst,ds,Element); 
    //waitKey(0);
}
void Tast_one::Task_one()
{
     //需要变量
    //寻找轮廓参数
    vector<vector<Point>>v1;
    vector<Vec4i>hierarchy;
    //绘制矩形
    Rect num;
    //感兴趣区域
    Mat roi;
    //判断
    bool x = false;
    //判断像素点、符合点参数
    int Point_count;
    
    //模版匹配数值
    double maxVal; 
    //原点（0，0）
	Point matchLoc = Point(0,0); 

    //选择算法变量：编号、最大值
    int numbers = -1;
    int Max = 0;
    
    //寻找轮廓
    findContours(ds,v1,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE);
    if(hierarchy.size()==0)
    {
        return ;
    }
    //选择最大轮廓面积
    for(size_t i =0;hierarchy.size()>i;i++)
    {
        num = boundingRect(v1[i]);
        if(Max<num.area())
        {
            numbers = i;
            Max = num.area();
        }
    }
    //cout<<"1.Max"<<Max;
    //淘汰面积不大的轮廓
    if(Max<ROI_BIG)
    {
        numbers = -1;
    }
    if(numbers!=-1)
    {
        num = boundingRect(v1[numbers]);
        zxc = num;
        //感兴趣区域赋值
        roi = src(num);
        ROI_1 = ds(num);
        ROI_2 = ROI_1.clone();
        ROI = roi.clone();
        maxVal = macth_green();
        //cout<<"模版匹配度"<<maxVal<<endl;
       
        //像素点匹配
        Point_count = point_macth();
        //cout<<"像素点匹配：："<<Point_count<<endl;
        x = analysis(num,maxVal,Point_count);
        if(x)
        {
            //cout<<"x"<<endl;
            // 通过判断后将ROI区域框出
            rectangle( roi, matchLoc, Point( matchLoc.x + ROI.cols , matchLoc.y + ROI.rows ), Scalar(0,0,255), 2, 8, 0 ); 
            putText(src ,"green",Point(num.x,num.y),FONT_HERSHEY_COMPLEX,0.5,Scalar(255,0,0));
            cout<<"绿灯"<<endl;
            conclusion = true;

        }
    }

}
double Tast_one::getDistance(Point A,Point B)
{
    double dis;
    dis=pow((A.x-B.x),2)+pow((A.y-B.y),2);
    return sqrt(dis);
}

void Tast_one::Frame_rate()
{
    // double wkj_time = double(finish-start)/CLOCKS_PER_SEC*1000;
    double wkj_Frame = 1000/(double(finish-start)/CLOCKS_PER_SEC*1000);
    // cout<<"算法进行时间为："<<time<<endl;
    // cout<<"视觉识别帧率为："<<Frame<<endl;
    std::string str = std::to_string(wkj_Frame);
    string Frame_name = "FPS:";
    Frame_name +=str;
    //cout<<"视觉识别帧率为："<<Frame_name<<endl;
    putText(src,Frame_name,Point(0,50),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255));
}

double Tast_one::macth_green()
{
     //模版匹配：匹配图像、映射图像、映射图像长、宽
    Mat greed_right1;
    Mat g_resultImage;
    int resultImage_cols, resultImage_rows;
    //映射图像初始化
    resultImage_cols = ROI.cols - ROI.cols +1;
    resultImage_rows = ROI.rows - ROI.rows +1;
    g_resultImage.create(resultImage_cols, resultImage_rows, CV_32FC1);

    //修改匹配图像大小，与感兴趣区域大小相同
    resize(greed_right,greed_right1,ROI.size());
     //模版匹配
    matchTemplate(ROI,greed_right1,g_resultImage,TM_CCORR);
    //映射图像 解析数据
    double minVal; 
	double maxVal; 
	Point minLoc; 
	Point maxLoc; 
        
	
	minMaxLoc( g_resultImage, &minVal, &maxVal, &minLoc, &maxLoc, Mat() ); /// 对于方法 SQDIFF 和 SQDIFF_NORMED, 越小的数值代表更高的匹配结果. 而对于其他方法, 数值越大匹配越好 
    return maxVal;
}
int Tast_one::point_macth()
{
    int Point_count =0;
    for(int i = 0;i<POINT_NUMBER;i++)
    {
        int x = rand()%ROI_2.cols-1;
        int y = rand()%ROI_2.rows-1;
        if(ROI_1.at<uchar>(y,x)!= 0)
        {
            Point_count++;
        }
    }
    return Point_count;
}
bool Tast_one::analysis(Rect&num,double&maxVal,int&Point_count)
{
    //两点间距离
    double dis;
    if(zxc.width!=0)
    {
        dis = getDistance(Point(num.x,num.y),Point(zxc.x,zxc.y));
    }
    if(maxVal>MAX_VAL&&Point_count>=POINT_NUMBER/2)
    {
        //二重判断舍去矩形位移差太大的图像
        if(dis>200)
        {
            zxc = Rect(0,0,0,0);
            return false;
        }
        else{
            return true;
        }
        
    }
    return false;
}

int Tast_one::doing()
{
    //循环遍历选项，直到找到摄像头（没加）

    VideoCapture capture(0);
    capture.set(CAP_PROP_EXPOSURE,5);
    initial();
    namedWindow("parameter",WINDOW_NORMAL);
    namedWindow("kk",WINDOW_NORMAL);
    createTrackbar("value","parameter",&value_min,value_max,NULL);
    while(1)
    {
        (capture)>>src;
        start=clock();

        Image_preprocessing();
        Task_one();
        finish=clock();
        Frame_rate();

        imshow("kk",src);
        waitKey(10);
        if(conclusion)
        {
            break;
        }
    }
    
    return 1;
}