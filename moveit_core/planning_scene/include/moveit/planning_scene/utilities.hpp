/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2023, PickNik Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of PickNik Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Andy Zelenak
  Description: Helper functions related to the Planning Scene
*/

#pragma once

#include <moveit/robot_model/robot_model.h>

namespace planning_scene
{

/**
 * Helper function to create a RobotModel from a urdf/srdf.
 * @param urdf_model The universal robot description
 * @param srdf_model The semantic robot description
 * @return nullptr on failure
 */
moveit::core::RobotModelPtr createRobotModel(const urdf::ModelInterfaceSharedPtr& urdf_model,
                                             const srdf::ModelConstSharedPtr& srdf_model);

/**
 * convert Pose msg to Eigen::Isometry, normalizing the quaternion part if necessary.
 * @param msg Input message
 * @param out Output Eigen transform
 */
void poseMsgToEigen(const geometry_msgs::msg::Pose& msg, Eigen::Isometry3d& out);

/** \brief Read a pose from text */
bool readPoseFromText(std::istream& in, Eigen::Isometry3d& pose);

/** \brief Write a pose to text */
void writePoseToText(std::ostream& out, const Eigen::Isometry3d& pose);

}  // namespace planning_scene
