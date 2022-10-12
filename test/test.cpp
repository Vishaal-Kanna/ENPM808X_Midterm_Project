/**
 * @file test.cpp
 * @authors Sahruday, Vishaal Kanna Sivakumar
 * @brief Test class for the PID controller
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <gtest/gtest.h>

#include <iostream>
#include <opencv2/opencv.hpp>
#include "../include/Detection_module.hpp"
#include "../include/Tracking_module.hpp"
#include "../include/Transformation_module.hpp"

/**
 * @brief Test to check the validity of Bounding box detector
 */

TEST(test1, checking_bbox_detector) {
  Detection_module detector;
  cv::Mat image(cv::Size(256,256),CV_8UC3,cv::Scalar(0,0,255));;
  EXPECT_NO_FATAL_FAILURE(detector.bbox_detector(image));
}

/**
 * @brief Test to check the validity of Non Maximum Supression
 */

TEST(test2, checking_nms) {
  cv::Rect bbox (0,0,256,256);
  std::vector<cv::Rect> bboxes;
  bboxes.push_back(bbox);
  bboxes.push_back(bbox);

  Detection_module detector;
  ASSERT_FLOAT_EQ(detector.nms(bboxes)==bboxes, 0);
}

