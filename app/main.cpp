/** MIT License
 * Copyright (c) 2022 Vishaal Kanna Sivakumar, Sahruday Patti
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
<<<<<<< HEAD
=======

#include <opencv2/dnn.hpp>
#include <opencv2/opencv.hpp>
>>>>>>> 15c6b16 (Vishaal (#6))
#include <opencv2/core/core.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/highgui/highgui.hpp>
<<<<<<< HEAD
#include <opencv2/opencv.hpp>

#include "../include/Detection_module.hpp"
#include "../include/ACME_robot.hpp"
=======

#include "../include/Detection_module.hpp"
>>>>>>> 15c6b16 (Vishaal (#6))

using namespace std;
using namespace cv;
using namespace dnn;

int main() {
  Detection_module detector;
<<<<<<< HEAD
  ACME_robot Robot;

  float intrinsic[3][3] = {{0.2, 0, 0},{0, 0.2, 0},{0, 0, 1}};
  float cam_to_rob[3][4] = {{1, 0, 0, 0},{0, 1, 0, 0},{0, 0, 1, 5}};

  Robot.set_transformation_parameters(intrinsic, cam_to_rob);
=======
>>>>>>> 15c6b16 (Vishaal (#6))
  Mat frame1 = imread(
      "/home/vishaal/Vishaal/UMD_Sem_3/ENPM808X/ENPM808X_Midterm_Project/"
      "test_img.jpg");

<<<<<<< HEAD
  Robot.read_video("/home/vishaal/Downloads/Aya Nakamura - Copines - Minny Park Choreography.mp4");
//   vector<cv::Rect> bboxes;

//   bboxes = detector.bbox_detector(frame1);
//   Robot.draw_bboxes(frame1, bboxes, 0);


=======
  detector.bbox_detector(frame1);
  
>>>>>>> 15c6b16 (Vishaal (#6))
  // std::string filename = "/home/sahu27/Downloads/video.mpg";
  // std::cout<<"Hi";
  // cv::VideoCapture capture(filename);
  // cv::Mat frame;

  // if( !capture.isOpened() )
  //     throw "Error when reading steam_avi";

  // cv::namedWindow( "w", 1);
  // for( ; ; ) {

  //   capture >> frame;
  //   if(frame.empty())

  //     break;
  //   imshow("w", frame);
  //   cv::waitKey(20); // waits to display frame

  //   }
  //   cv::waitKey(0);
<<<<<<< HEAD
=======
  

  return 0;
>>>>>>> 15c6b16 (Vishaal (#6))

  return 0;
}






