#include <iostream>
#include <Eigen/Core>
#include <hpx/hpx_main.hpp>

using namespace Eigen;
int main() {
    initParallel();
    Matrix<double, 1, 3> a{1,2,3};
    Matrix<double, 100, 100> b,c,d;
    d = b * c;
    return 0;
}
