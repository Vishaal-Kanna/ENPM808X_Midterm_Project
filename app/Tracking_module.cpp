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
 * @file Tracking_module.cpp
 * @authors Sahruday Patti, Vishaal Kanna Sivakumar
 * @brief Stub class for the Tracking module class
 * @version 0.1
 * @date 2022-10-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/Tracking_module.hpp"

std::unordered_map<int, cv::Rect> Tracking_module::set_track_ids(
    std::vector<cv::Rect> bboxes) {
  for (size_t i = 0; i < bboxes.size(); i++) {
    _track_ids[i] = bboxes[i];
  }
  return _track_ids;
}

std::unordered_map<int, cv::Rect> Tracking_module::euclidean_tracker(
    std::vector<cv::Rect> bboxes) {
  std::unordered_map<int, cv::Rect> temp_ids;
  for (auto track_id : _track_ids) {
    float dist_min = 1000000;

    cv::Point center_of_rect_prev =
        (track_id.second.br() + track_id.second.tl()) * 0.5;
    for (size_t i = 0; i < bboxes.size(); i++) {
      cv::Point center_of_rect_current =
          (bboxes[i].br() + bboxes[i].tl()) * 0.5;
      float dist = norm(center_of_rect_prev - center_of_rect_current);
      if (dist < dist_min) {
        dist_min = dist;
        temp_ids[track_id.first] = bboxes[i];
      }
    }
  }

  _track_ids = temp_ids;

  return _track_ids;
}
