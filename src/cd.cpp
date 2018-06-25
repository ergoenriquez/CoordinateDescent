//============================================================================
// Name        : cd.cpp
// Author      : Jason Enriquez
// Version     :
// Copyright   :
// Description : Coordinate Descent in C++ using Eigen
//============================================================================

#include "cd.hpp"
#include <cmath>
#include "Eigen/Dense"

using namespace Eigen;
using namespace std;

Eigen::VectorXf coordinate_descent(const Eigen::MatrixXf& X, const Eigen::VectorXf& y, float alpha, int n_iter) {
	int n_samples, n_features, i, j;
	float dotp;

	n_samples = X.rows();
	n_features = X.cols();

	Eigen::VectorXf w(n_features);
	for(i = 0; i < n_features; ++i) {
		w(i) = 0.0;
	}

	Eigen::VectorXf r_j(n_samples);
	for (i = 0; i < n_iter; ++i) {
		for (j = 0; j < n_features; ++j) {
			w(j) = 0.0;
			r_j = y - X * w;
			dotp = X.col(j).dot(r_j)/n_samples;
			w(j) = soft_threshold(dotp, alpha);
		}
	}
	return w;
}

float soft_threshold(float X, float thresh) {
	if (abs(X) <= thresh) {
		return 0;
	} else if (X > 0) {
		return X - thresh;
	} else if (X < 0) {
		return X + thresh;
	} else {
		return X;
	}
}


