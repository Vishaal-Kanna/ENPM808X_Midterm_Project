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
 * @file ACME_robot.cpp
 * @authors Sahruday Patti, Vishaal Kanna Sivakumar
 * @brief Stub class for the ACME Robot
 * @version 0.1
 * @date 2022-10-10
 *
 * @copyright Copyright (c) 2022
 *
 */


#include "../include/ACME_robot.hpp"


void ACME_robot::set_detector_parameters(int img_width, int img_height,
                                         float conf_threshold,
                                         float nms_threshold) {
  detector.set_img_width(img_width);
  detector.set_img_height(img_height);
  detector.set_conf_threshold(conf_threshold);
  detector.set_nms_threshold(nms_threshold);
}

void ACME_robot::set_transformation_parameters(float intrinsic[3][3],
                                               float cam_to_rob[3][4]) {
  transforms.set_intrinsics(intrinsic);
  transforms.set_cam_to_rob(cam_to_rob);
}

int ACME_robot::perception_stack(cv::Mat frame, int frame_no) {
  int width = frame.cols;
  int height = frame.rows;
  int down_width = detector.get_img_width();
  int down_height = detector.get_img_height();

  std::vector<cv::Rect> bboxes_after_nms;
  std::unordered_map<int, cv::Rect> bboxes_with_ids;

  cv::resize(frame, frame, cv::Size(down_width, down_height), cv::INTER_LINEAR);
  bboxes_after_nms = detector.bbox_detector(frame);
  if (frame_no == 1 && bboxes_after_nms.size() > 0) {
    bboxes_with_ids = tracker.set_track_ids(bboxes_after_nms);
    frame_no++;
    _no_of_bboxes = bboxes_after_nms.size();
  } else if (bboxes_after_nms.size() != _no_of_bboxes) {
    bboxes_with_ids = tracker.set_track_ids(bboxes_after_nms);
    frame_no = 1;
    _no_of_bboxes = bboxes_after_nms.size();
  } else {
    bboxes_with_ids = tracker.euclidean_tracker(bboxes_after_nms);
    _no_of_bboxes = bboxes_after_nms.size();
  }

  draw_bboxes(frame, bboxes_with_ids, width, height);

  return frame_no;
}

void ACME_robot::draw_bboxes(cv::Mat frame,
                             std::unordered_map<int, cv::Rect> bboxes_with_ids,
                             int width, int height) {
  int up_width = width;
  int up_height = height;

  cv::resize(frame, frame, cv::Size(up_width, up_height), cv::INTER_LINEAR);

  for (auto bbox_with_id : bboxes_with_ids) {
    cv::Rect temp = cv::Rect(bbox_with_id.second.x * width / 416.0,
                             bbox_with_id.second.y * height / 416.0,
                             bbox_with_id.second.width * width / 416.0,
                             bbox_with_id.second.height * height / 416.0);
    std::array<float, 4> coord = transforms.transform_2dto3D(temp);
    cv::rectangle(frame, cv::Point(temp.x, temp.y),
                  cv::Point(temp.x + temp.width, temp.y + temp.height),
                  cv::Scalar(255, 178, 50), 2);
    cv::putText(frame,
                std::to_string(bbox_with_id.first) + "-[" +
                    std::to_string(static_cast<int>(coord[0])) + "," +
                    std::to_string(static_cast<int>(coord[1])) + "," +
                    std::to_string(static_cast<int>(coord[2])) + "]",
                cv::Point(temp.x - 10, temp.y - 10), cv::FONT_HERSHEY_DUPLEX,
                0.75, CV_RGB(118, 185, 0), 0.75);
  }
  cv::imshow("Frame", frame);
  cv::waitKey(0);
}

void ACME_robot::read_video(std::string filename) {
  cv::VideoCapture capture(filename);
  cv::Mat frame;

  int frame_no = 1;

  if (!capture.isOpened()) throw "Error when reading steam_avi";

  for (;;) {
    capture >> frame;
    if (frame.empty()) break;
    frame_no = perception_stack(frame, frame_no);
  }
}

void ACME_robot::live_video(int camera_id) {
  cv::VideoCapture capture(camera_id);
  cv::Mat frame;

  int frame_no = 1;

  if (!capture.isOpened()) throw "Error when reading steam_avi";

  for (;;) {
    capture >> frame;
    if (frame.empty()) break;
    frame_no = perception_stack(frame, frame_no);
  }
}
