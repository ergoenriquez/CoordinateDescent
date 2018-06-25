//============================================================================
// Name        : cd.hpp
// Author      : Jason Enriquez
// Version     :
// Copyright   :
// Description : Coordinate Descent header file
//============================================================================

#ifndef SRC_CD_HPP_
#define SRC_CD_HPP_

#include <cmath>
#include "Eigen/Dense"

Eigen::VectorXf coordinate_descent(const Eigen::MatrixXf& X, const Eigen::VectorXf& y, float alpha, int n_iter);
float soft_threshold(float X, float thresh);

#endif /* SRC_CD_HPP_ */
