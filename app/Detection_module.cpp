/**
 * @file Detection_module.cpp
 * @authors Sahruday Patti, Vishaal Kanna Sivakumar
 * @brief Stub class for the Detection module class
 * @version 0.1
 * @date 2022-10-10
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

std::vector<cv::Rect> Detection_module::bbox_detector(cv::Mat image)
{ image = image*0;
  std::vector<cv::Rect>bboxes;
  return bboxes;
}

float Detection_module::calc_IOU(cv::Rect bbox1, cv::Rect bbox2){
  return 3.6;
}

std::vector<cv::Rect> Detection_module::nms(std::vector<cv::Rect>)
{ 
  std::vector<cv::Rect>bboxes_after_nms;
  return bboxes_after_nms;
}
