=========================================================
 Name        : readme.txt
 Author      : Jason Enriquez
 Version     :
 Copyright   :
 Description : Coordinate Descent Unit Test Read Me file
=========================================================

This C++ code (migrated from Python with Numpy) for Coordinate Descent algorithm utilizes the Eigen library. Thus, it is necessary to include the library during build using GCC as follows:

g++ -I \path\to\eigen -O2 -DNDEBUG "src\test_cd.cpp" "src\cd.cpp" -o CoordinateDescent

cd.cpp contains the algorithm while test_cd contains the unit test code.

In case no pre-existing Eigen library is installed in your system, please feel free to use the one included in \src\Eigen.

The -O2 -DNDEBUG option is added for performance optimization. Matrix multiplication in Eigen seemed to take significantly longer if this optimization option is not enabled.

To run the program, execute the resulting CoordinateDescent.exe file.