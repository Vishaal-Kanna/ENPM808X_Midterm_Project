/**
 * @file test.cpp
 * @authors Rishabh Singh, Vishaal Kanna Sivakumar
 * @brief Test class for the PID controller
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <gtest/gtest.h>

#include <iostream>

#include "../include/pid.hpp"

/**
 * @brief Test to check the values of the PID constants
 */

TEST(test1, checking_PID_constants) {
  pid::PID controller;
  controller.setKp(0.4);
  controller.setKd(0.3);
  controller.setKi(0.1);
  controller.setTstep(0.1);
  ASSERT_DOUBLE_EQ(controller.getKp(), 0.4);
  ASSERT_DOUBLE_EQ(controller.getKd(), 0.3);
  ASSERT_DOUBLE_EQ(controller.getKi(), 0.1);
  ASSERT_FLOAT_EQ(controller.getTstep(), 0.1);
}

/**
 * @brief Test to check the controller command computed by the PID class method
 * computeCommand should return the controller command and not the final velocity.
 */

TEST(test2, checking_compute_Controller_Command_method) {
  pid::PID controller;
  controller.setKp(0.4);
  controller.setKd(0.3);
  controller.setKi(0.1);
  controller.setTstep(0.1);
  EXPECT_NEAR(controller.computeCommand(50, 0, 50), 170.5, 0.01);
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
