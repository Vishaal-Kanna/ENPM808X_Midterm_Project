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

#include "../include/Detection_module.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

/**
 * @brief Test to check the validity of Bounding box detector
 */

TEST(test1, checking_bbox_detector) {
  Detection_module detector;
  cv::Mat image = cv::imread("../test_img.png");
  EXPECT_NO_FATAL_FAILURE(detector.bbox_detector(image));
}

/**
 * @brief Test to check the validity of Non Maximum Supression
 */

TEST(test2, checking_nms) {
  cv::rect bbox (0,0,256,256);
  std::vector bboxes;
  bboxes.pushback(bbox);
  bboxes.pushback(bbox);

  Detection_module detector;
  ASSERT_FLOAT_EQ(detector.nms(bboxes), bbox);
}

/**
 * @brief Test to check if the time step value is assigned to 0.1 if the input 
 * is lesser than or equal to zero.
 */
TEST(test3, checking_Time_step) {
  pid::PID controller;
  controller.setTstep(-1);
  ASSERT_FLOAT_EQ(controller.getTstep(), 0.1);
}
