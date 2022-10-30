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
#include "../include/ACME_robot.hpp"
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
 * @brief Test to check the validity setter functions
 */

TEST(test4, checking_set_functions_for_detector) {
  Detection_module detector;
  EXPECT_NO_FATAL_FAILURE(detector.set_img_width(5));
  EXPECT_NO_FATAL_FAILURE(detector.set_img_height(5));
  EXPECT_NO_FATAL_FAILURE(detector.set_conf_threshold(0.2));
  EXPECT_NO_FATAL_FAILURE(detector.set_nms_threshold(0.5));
  EXPECT_NO_FATAL_FAILURE(detector.get_img_height());
  EXPECT_NO_FATAL_FAILURE(detector.get_img_width());
}

TEST(test5, checking_transformation_module_functions) {
  Transformation_module Transform;
  float intrinsics[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  float cam_to_rob[3][4] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  cv::Rect rect;
  ASSERT_NO_THROW(Transform.set_cam_to_rob(cam_to_rob));
  ASSERT_NO_THROW(Transform.set_intrinsics(intrinsics));
  ASSERT_NO_THROW(Transform.transform_2dto3D(rect));
}

TEST(test6, checking_tracking_module_functions) {
  Tracking_module tracker;
  float intrinsics[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  float cam_to_rob[3][4] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  std::vector<cv::Rect> rect;
  ASSERT_NO_THROW(tracker.set_track_ids(rect));
  ASSERT_NO_THROW(tracker.euclidean_tracker(rect));
}

TEST(test7, checking_ACME_robot_functions) {
  ACME_robot Robot;
  cv::Mat image(cv::Size(416, 416), CV_8UC3, cv::Scalar(0, 0, 255));
  float intrinsics[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  float cam_to_rob[3][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  std::unordered_map<int, cv::Rect> bboxes_with_ids;
  EXPECT_NO_FATAL_FAILURE(Robot.set_detector_parameters(416,416,0.5,0.5));
  EXPECT_NO_FATAL_FAILURE(Robot.set_transformation_parameters(intrinsics,cam_to_rob));
  EXPECT_NO_FATAL_FAILURE(Robot.perception_stack(image, 1));
  EXPECT_NO_FATAL_FAILURE(Robot.draw_bboxes(image, bboxes_with_ids, 416, 416));
  EXPECT_NO_FATAL_FAILURE(Robot.read_video("/home/vishaal/Downloads/test_video.mp4"));
  EXPECT_NO_FATAL_FAILURE(Robot.live_video(0));
}

