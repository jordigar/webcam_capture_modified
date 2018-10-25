
//opencv
#include "opencv2/opencv.hpp"

//std
#include <iostream>
#include <cstdlib>

//main
int main(int argc, char *argv[])
{
    cv::VideoCapture camera; //OpenCV video capture object
    cv::Mat image, image1; //OpenCV image object
	int cam_id; //camera id . Associated to device number in /dev/videoX
	cv::Scalar_<unsigned char> px_value; //pixel value (4-element vector)
	int user_key; //user pressed key to quit

	//check user args
	switch(argc)
	{
		case 1: //no argument provided, so try /dev/video0
			cam_id = 0;
			break;
		case 2: //an argument is provided. Get it and set cam_id
			cam_id = atoi(argv[1]);
			break;
		default:
			std::cout << "Invalid number of arguments. Call program as: webcam_capture [video_device_id]. " << std::endl;
			std::cout << "EXIT program." << std::endl;
			break;
	}

	//advertising to the user
	std::cout << "Opening video device " << cam_id << std::endl;

    //open the video stream and make sure it's opened
    if( !camera.open(cam_id) )
	{
        std::cout << "Error opening the camera. May be invalid device id. EXIT program." << std::endl;
        return -1;
    }

    //capture loop. Out of user press a key
    while(1)
	{
		//Read image and check it. Blocking call up to a new image arrives from camera.
        if(!camera.read(image))
		{
            std::cout << "No frame" << std::endl;
            cv::waitKey();
        }

        //show image in a window
        cv::imshow("Output Window", image);
	image1=image;
	std::cout << "Number of rows:" << image1.rows << std::endl;
	std::cout << "Number of colums:" << image1.cols << std::endl;
	//px_value = image1.at<int>(270,480);
	px_value = image1.at<int>(image1.rows/2,image1.cols/2);
	std::cout << "Value of central pixel:" << px_value << std::endl;
	//px_value = (100,0,0,0);
	//for(int i = 0; i < image1.rows; i++)
	//for(int i = 270; i < 370; i++)
	//{
    		//for(int j = 0; j < image1.cols; j++)
	//	for(int j = 480; j < 580; j++)
	//	{
        //		image1.at<int>(i,j)=px_value;
	//	}
	//}
	//image1=px_value;
	//Mat roi(image1, Rect(10,10,100,100));
	// fill the ROI with (0,255,0) (which is green in RGB space);
	// the original image will be modified
	//roi = px_value (0,255,0);
	cv::imshow("Output Window 2", image1);

		//Waits 30 millisecond to check if 'q' key has been pressed. If so, breaks the loop. Otherwise continues.
    	if( (unsigned char)(cv::waitKey(30) & 0xff) == 'q' ) break; 
    }
}
