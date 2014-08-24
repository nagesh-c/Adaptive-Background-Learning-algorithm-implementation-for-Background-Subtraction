#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>
#include "AdaptiveBackgroundLearning.h"
#include <conio.h>

using namespace std;
using namespace cv;

int main(int argc,char **argv)
{
	Mat frame_aux,frame;
	int width,height,resize_factor=100,key = 0;
	VideoCapture cap("E:\\Moving Object Tracking under Water Video Sequence\\videos\\AF004_0136(S).mov");
	if(!cap.isOpened())
	{
		cout<<"error cannot openfile"<<endl;
		return -1;
	}
	
	AdaptiveBackgroundLearning* bgs = new AdaptiveBackgroundLearning;
	
	while(key != 'q')
	{
		cap.read(frame_aux);
		if(frame_aux.empty()) {break;}
		
		resize(frame_aux,frame,Size(320,200),0,0,1);
    
		cv::Mat img_input(frame);
		namedWindow("input",CV_WINDOW_AUTOSIZE);
		cv::imshow("input", img_input);

		cv::Mat img_output;
		cv::Mat img_bkgmodel;
		bgs->process(img_input, img_output, img_bkgmodel); // by default, it shows automatically the foreground mask image
  
		key = cvWaitKey(33);
	}
	delete bgs;
	cvDestroyAllWindows();
	getch();
	return 0;
}