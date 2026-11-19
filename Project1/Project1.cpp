#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	//项目绝对路径
	const string abslutePath = "G:/Developer/repos/ComputerVisionProject/";
	// 读入一张图片
	const string imagePath = abslutePath + "data/实验一原始图.jpg";
	const cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

	// 转为灰度图
	cv::Mat gray(image.rows, image.cols, CV_8UC1);
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			const cv::Vec3b& pixel = image.at<cv::Vec3b>(y, x);
			unsigned int b = pixel[0];
			unsigned int g = pixel[1];
			unsigned int r = pixel[2];

			unsigned int value = 0.114 * b + 0.587 * g + 0.299 * r;
			gray.at<unsigned char>(y, x) = static_cast<unsigned char>(value);
		}
	}

	// 输出灰度值到文件
	const string filePath = abslutePath + "data/实验一原始图gray.txt";
	ofstream file(filePath);

	for (int y = 0; y < gray.rows; y++) {
		for (int x = 0; x < gray.cols; x++) {
			unsigned int value = gray.at<unsigned char>(y, x);
			file << value << ' ';

		}
		file << '\n';
	}
	file.close();

	// 灰度图变换
	cv::Mat modified_gray(image.rows, image.cols, CV_8UC1);
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			unsigned int px = gray.at<unsigned char>(y, x);

			unsigned int value = px * 2 + 20 <= 255 ? px * 2 + 20 : 255;
			modified_gray.at<unsigned char>(y, x) = static_cast<unsigned char>(value);
		}
	}

	//图片展示
	cv::imshow("Original", image);
	cv::imshow("Gray", gray);
	cv::imshow("ModifiedGray", modified_gray);
	cv::waitKey(0);
	return 0;
}