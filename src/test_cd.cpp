//============================================================================
// Name        : test_cd.cpp
// Author      : Jason Enriquez
// Version     :
// Copyright   :
// Description : Coordinate Descent Unit Test in C++
//============================================================================

#include <iostream>
#include <ctime>
#include <Eigen/Dense>
#include <random>
#include "cd.hpp"

using namespace Eigen;
using namespace std;

int main() {
	int n_features, n_samples, n_nonzero_coefs, n_iter, i, j, nz_true, nz_pred;
	float alpha;

	n_features = 1000;
	n_samples = 100;
	n_nonzero_coefs = 20;
	n_iter = 1000;
	alpha = 0.6;

	// True weight generation (idx and w)
	srand(time(NULL));	// random integer generator seed

	VectorXi idx(n_nonzero_coefs);
	for(i = 0; i < n_nonzero_coefs; ++i) {
		idx(i) = (rand() %n_features) + 1;
	}

    std::random_device rd;  // random device class instance; seed for number generator
    std::mt19937 gen(rd()); // Mersenne Twister number generator; initialized with seed from above instance
    std::normal_distribution<float> nd(0.0, 1.0); //random generator from normal distribution

	VectorXf w(n_features);
	for(i = 0; i < n_features; ++i) {
		w(i) = 0.0;
		for(j = 0; j < n_nonzero_coefs; ++j) {
			if (idx(j)==i) {
				w(i) = nd(gen);
			}
		}
	}

	// Input data and observation info (X and y)
	MatrixXf X(n_samples, n_features);
	for(i = 0; i < n_samples; ++i) {
		for(j = 0; j < n_features; ++j) {
			X(i,j) = nd(gen);
		}
	}

	VectorXf rc(n_samples);
	for(i = 0; i < n_samples; ++i) {
		rc(i) = nd(gen);
	}

	VectorXf y(n_samples);
	y = X * w + rc;

	//coordinate descent execution
	VectorXf w_pred(n_features);
	w_pred = coordinate_descent(X, y, alpha, n_iter);

	//number of non zero elements
	nz_true = 0;
	nz_pred = 0;
	for(i = 0; i < n_features; ++i) {
		if (w(i)!=0) {
			++nz_true;
		}
		if (w_pred(i)!=0) {
			++nz_pred;
		}
	}

	std::cout << "Results:\n";
	std::cout << "Number of nonzero coefficients (true) : " << nz_true << "\n";
	std::cout << "Number of nonzero coefficients (predicted) : " << nz_pred << "\n";

	//Euclidean distances
	VectorXf coef_v(n_features);
	coef_v = w - w_pred;

	VectorXf est_v(n_samples);
	est_v = y - X * w_pred;

	std::cout << "Euclidean distance between coefficients : " << coef_v.norm() << "\n";
	std::cout << "Euclidean distance between estimated output : " << est_v.norm() << "\n";

	std::cout << "Test Parameters:";
	std::cout << "\n n_features: " << n_features;
	std::cout << "\n n_samples: " << n_samples;
	std::cout << "\n n_nonzero_coefs: " << n_nonzero_coefs;
	std::cout << "\n n_iter: " << n_iter;
	std::cout << "\n alpha: " << alpha << "\n\n";

	system("PAUSE");

	return 0;
}
