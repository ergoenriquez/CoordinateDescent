============================================================================
 Name        : readme.txt
 Author      : Jason Enriquez
 Version     :
 Copyright   :
 Description : Coordinate Descent Unit Test Read Me file
============================================================================

This C++ code (migrated from Python) for Coordinate Descent algorithm utilizes the Eigen library. Thus, it is necessary to include the library during build using GCC as follows:

g++ -I /path/to/eigen/ -O2 -DNDEBUG "..\src\test_cd.cpp" "..\src\cd.cpp" -o CoordinateDescent

The -O2 -DNDEBUG option is added for performance optimization (matrix multiplication in Eigen seemed to take significantly longer if optimization is not enabled).

