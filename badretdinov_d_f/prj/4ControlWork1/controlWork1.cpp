#include <opencv2/opencv.hpp>
#include<vector>
#include<highgui.h>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	Mat image(400, 1200, CV_8UC1);
	const Scalar black(0);
	const Scalar grey(128);
	const Scalar white(255);

	rectangle(image, Rect(0, 0, 200, 200), grey, -1, 8, 0);
	rectangle(image, Rect(200, 0, 200, 200), white, -1, 8, 0);
	rectangle(image, Rect(400, 0, 200, 200), black, -1, 8, 0);
	rectangle(image, Rect(600, 0, 200, 200), white, -1, 8, 0);
	rectangle(image, Rect(800, 0, 200, 200), black, -1, 8, 0);
	rectangle(image, Rect(1000, 0, 200, 200), grey, -1, 8, 0);

	rectangle(image, Rect(0, 200, 200, 200), grey, -1, 8, 0);
	rectangle(image, Rect(200, 200, 200, 200), white, -1, 8, 0);
	rectangle(image, Rect(400, 200, 200, 200), black, -1, 8, 0);
	rectangle(image, Rect(600, 200, 200, 200), white, -1, 8, 0);
	rectangle(image, Rect(800, 200, 200, 200), black, -1, 8, 0);
	rectangle(image, Rect(1000, 200, 200, 200), grey, -1, 8, 0);

	rectangle(image, Rect(30, 30, 140, 140), black, -1, 8, 0);
	rectangle(image, Rect(230, 30, 140, 140), black, -1, 8, 0);
	rectangle(image, Rect(430, 30, 140, 140), grey, -1, 8, 0);
	rectangle(image, Rect(630, 30, 140, 140), grey, -1, 8, 0);
	rectangle(image, Rect(830, 30, 140, 140), white, -1, 8, 0);
	rectangle(image, Rect(1030, 30, 140, 140), white, -1, 8, 0);

	circle(image, Point(100, 300), 80, black, -1, 8, 0);
	circle(image, Point(300, 300), 80, black, -1, 8, 0);
	circle(image, Point(500, 300), 80, grey, -1, 8, 0);
	circle(image, Point(700, 300), 80, grey, -1, 8, 0);
	circle(image, Point(900, 300), 80, white, -1, 8, 0);
	circle(image, Point(1100, 300), 80, white, -1, 8, 0);

	Mat outputImage;
	char ker[2][2] = { { 1, 0 }, { 0, -1 } };
	
	Mat kernel(2, 2, CV_8SC(1), ker);

	filter2D(image, outputImage, CV_32F, kernel, Point(-1, -1), 0, BORDER_DEFAULT);
	outputImage *= 127 / 255.0;
	for (int i = 0; i < outputImage.rows; ++i)
	{
		for (int j = 0; j < outputImage.cols; ++j)
		{
			outputImage.at<float>(i, j) += 127;
		}
	}
	Mat convertedOutputImage;
	outputImage.convertTo(convertedOutputImage, CV_8U);

	imshow("", convertedOutputImage);
	waitKey(0);
}