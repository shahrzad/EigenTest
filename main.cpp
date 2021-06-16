#include <iostream>
#include <Eigen/Core>
using namespace Eigen;
int main() {
    initParallel();
    Matrix<double, 1, 3> a{1,2,3};
    std::cout << a << std::endl;
    return 0;
}
