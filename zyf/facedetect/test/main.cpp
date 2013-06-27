#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

 /** 全局变量 */
 string face_cascade_name = "haarcascade_frontalface_alt.xml";
 string eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
 CascadeClassifier face_cascade;
 CascadeClassifier eyes_cascade;
 string window_name = "Capture - Face detection";

/** @函数 detectAndDisplay */
void detectAndDisplay(Mat frame, string path)
{
  vector<Rect> faces;
  Mat frame_gray;

  cvtColor( frame, frame_gray, CV_BGR2GRAY );
  equalizeHist( frame_gray, frame_gray );

  //-- 多尺寸检测人脸
  face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
  if (faces.size() != 1) return;
  Mat face = frame_gray(faces[0]), face_resized;
  resize(face, face_resized, Size(100, 100), 1.0, 1.0, INTER_CUBIC);
  //imwrite("face.jpg", face_resized);
  imwrite(path, face_resized);
  /*
  for( int i = 0; i < faces.size(); i++ )
  {
    Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
    ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

    Mat faceROI = frame_gray( faces[i] );
    vector<Rect> eyes;

    //-- 在每张人脸上检测双眼
    eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );

    for (int j = 0; j < eyes.size(); j++) {
		printf("%d %d\n", faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
		Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
		int radius = cvRound( (eyes[j].width + eyes[i].height)*0.25 );
		circle( frame, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
    }
  }
  */
  //-- 显示结果图像
  //imshow( window_name, frame );
  //waitKey();
}

static void read_csv(const string& filename, char separator = ';') 
{
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file) {
        string error_message = "No valid input file was given, please check the given filename.";
        CV_Error(CV_StsBadArg, error_message);
    }
    string line, path, classlabel;
    while (getline(file, line)) {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        if(!path.empty() && !classlabel.empty()) {
            Mat img = imread(path);
			detectAndDisplay(img, path);
        }
    }
}

int main()
{
	//-- 1. 加载级联分类器文件
	if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
	if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
	/*
	Mat img = imread("lena.jpg");
    if(img.empty())
    {
        cout<<"error";
        return -1;
    }
    detectAndDisplay(img);
	*/
    string fn_csv = "database.csv";
	try {
        read_csv(fn_csv);
    } catch (cv::Exception& e) {
        cerr << "Error opening file \"" << fn_csv << "\". Reason: " << e.msg << endl;
        // nothing more we can do
        exit(1);
    }
    return 0;
}