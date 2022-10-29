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

#include <cstddef>
#include <iostream>
#include <vector>

std::unordered_map<int, cv::Rect> Tracking_module::set_track_ids(std::vector<cv::Rect> bboxes) {
  for(int i=0; i<bboxes.size(); i++) {
  _track_ids[i] = bboxes[i];}
  return _track_ids;
}

std::unordered_map<int, cv::Rect> Tracking_module::euclidean_tracker(std::vector<cv::Rect> bboxes) {
  std::unordered_map<int, cv::Rect> temp_ids;
  for (auto track_id:_track_ids) {
    double value = 0.0;
    double value_prev = 0.0;
    double distance_prev = 0.0;
    double distance = 0.0;
    float dist_min = 1000000;
    
    cv::Point center_of_rect_prev = (track_id.second.br() + track_id.second.tl())*0.5;
    for(int i=0; i<bboxes.size(); i++)
    { cv::Point center_of_rect_current = (bboxes[i].br() + bboxes[i].tl())*0.5;
      float dist = norm(center_of_rect_prev-center_of_rect_current);
      if(dist<dist_min)
      {dist_min = dist;
       temp_ids[track_id.first] = bboxes[i];}}}
      

  //   cv::Point center_of_rect = (r.br() + r.tl())*0.5;
  //   for (cv::Rect r_prev : bboxes_frame1) {
  //     cv::Point center_of_rect_prev = (r_prev.br() + r_prev.tl())*0.5;
  //     value_prev = norm(center_of_rect_prev);
  //     value = norm(center_of_rect);
  //     distance_prev = abs(value_prev - value);
  //     if(i == 0) {
  //       distance = distance_prev;
  //     }
  //     if (distance_prev < distance){
  //       cv::Rect tracked_rect = r
  //     }
  //   }
  // }
    _track_ids = temp_ids;

  return _track_ids;


}
