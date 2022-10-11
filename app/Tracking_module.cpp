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

std::vector<cv::rect> Tracking_module::hungarian_algorithm(std::vector<cv::rect> bboxes_frame1, std::vector<cv::rect> bboxes_frame2);
{ _img_width = val; }

void Detection_module::set_img_height(int val)
{ _img_height = val; }

void Detection_module::set_conf_threshold(float val)
{ _conf_threshold = val; }

void Detection_module::set_nms_threshold(float val)
{ _nms_threshold = val; }

std::vector<cv::rect> Detection_module::bbox_detector(cv::Mat image)
{ std::vector<cv::rect>bboxes;
  return bboxes;
}

std::vector<cv::rect> Detection_module::nms(std::vector<cv::rect>)
{ 
  std::vector<cv::rect>bboxes_after_nms;
  return bboxes_after_nms;
}
