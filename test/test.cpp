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
 * @file test.cpp
 * @authors Sahruday Patti, Vishaal Kanna Sivakumar
 * @brief Test class for the all the modules
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <gtest/gtest.h>

#include <iostream>
// #include <opencv2/opencv.hpp>
#include "../include/Detection_module.hpp"
#include "../include/Tracking_module.hpp"
#include "../include/Transformation_module.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

/**
 * @brief Test to check the validity of Bounding box detector
 */

TEST(test1, checking_bbox_detector) {
  Detection_module detector;
  cv::Mat image(cv::Size(416, 416), CV_8UC3, cv::Scalar(0, 0, 255));
  EXPECT_NO_FATAL_FAILURE(detector.bbox_detector(image));
}

/**
 * @brief Test to check the validity of Non Maximum Supression
 */

TEST(test2, checking_nms) {
  cv::Rect bbox(0, 0, 256, 256);
  std::vector<cv::Rect> bboxes;
  bboxes.push_back(bbox);
  bboxes.push_back(bbox);

  Detection_module detector;
  EXPECT_NO_FATAL_FAILURE(detector.nms(bboxes));
}

/**
 * @brief Test to check the output of IOU
 */

TEST(test3, chacking_Calc_IOU) {
  Detection_module detect_object;
  cv::Rect r1 = cv::Rect(0, 0, 10, 10);
  cv::Rect r2 = cv::Rect(5, 5, 10, 10);
  auto output = detect_object.calc_IOU(r1, r2);
  ASSERT_NEAR(output, 0.166, 1);
}

/**
 * @brief Test to check the validity setter functions
 */

TEST(test4, checking_set_functions) {
  Detection_module detector;
  EXPECT_NO_FATAL_FAILURE(detector.set_img_width(5));
  EXPECT_NO_FATAL_FAILURE(detector.set_img_height(5));
  EXPECT_NO_FATAL_FAILURE(detector.set_conf_threshold(0.2));
  EXPECT_NO_FATAL_FAILURE(detector.set_nms_threshold(0.5));
}
