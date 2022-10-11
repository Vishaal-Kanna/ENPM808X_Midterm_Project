/**
 * @file pid.cpp
 * @authors Rishabh Singh, Vishaal Kanna Sivakumar
 * @authors Part 2: Sanchit Kedia, Adarsh Malapaka
 * @brief Stub class for the PID controller
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/Tracking_module.hpp"

#include <iostream>
#include <vector>

void Tracking_module::set_track_ids(std::unordered_map<int, cv::Rect> tracks){
  _track_ids = tracks;
}

std::vector<cv::Rect> Tracking_module::hungarian_algorithm(std::vector<cv::Rect> bboxes_frame1, std::vector<cv::Rect> bboxes_frame2)
{ cv::Rect bbox (0,0,256,256);
  std::vector<cv::Rect> bboxes;
  bboxes.push_back(bbox);
  bboxes.push_back(bbox);
  return bboxes; }

void Tracking_module::track_human(cv::Mat image1, cv::Mat image2){

}



