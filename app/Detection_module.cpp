/**
 * @file pid.cpp
 * @authors Sahruday, Vishaal Kanna Sivakumar
 * @brief Stub class for the Detection module
 * @version 0.1
 * @date 10/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/Detection_module.hpp"

void Detection_module::set_img_width(int val)
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
