/**
 * @file main.cpp
 * @authors Sahruday Patti, Vishaal Kanna Sivakumar
 * @brief main function for Human Tracking
 * @version 0.1
 * @date 2022-10-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include "../include/Detection_module.hpp"

using namespace std;
using namespace cv;
using namespace dnn;

int main() {

  Detection_module detector;
  Mat frame1 = imread("/home/vishaal/Vishaal/UMD_Sem_3/ENPM808X/ENPM808X_Midterm_Project/karina-carvalho-fKTKVrNqXQQ-unsplash.jpg");

  detector.bbox_detector(frame1);
  return 0;
}
