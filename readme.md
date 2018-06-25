# Simplified Coordinate Descent Algorithm

## DOWNLOAD

To download the repository, go to a local directory of your preference then run the following command in Git Bash:

`$ git clone https://github.com/ergoenriquez/CoordinateDescent.git`

## BUILD

This Coordinate Descent algorithm migrated to C++ (from Python & NumPy) utilizes the Eigen library. 
Hence, it is necessary to include the library during build using GCC as follows:

### Short way
`$ make`

### Long way
`$ g++ -I "Eigen/" -O2 -DNDEBUG "test_cd.cpp" "cd.cpp" -o CoordinateDescent --verbose`

### Clean
`$ make clean`

For your reference, "cd.cpp" contains the algorithm while "test_cd.cpp" contains the unit test code.

The `-O2 -DNDEBUG` option is added for performance optimization.
Matrix multiplication in Eigen seemed to take significantly longer if this optimization option is not enabled.

## RUN

To run the program, execute as follows:

`$ ./CoordinateDescent`
