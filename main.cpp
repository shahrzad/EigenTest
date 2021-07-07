#include <iostream>
#include <Eigen/Core>
#include <chrono>
#ifdef EIGEN_HAS_HPX
#include <hpx/hpx_main.hpp>
#endif

using namespace Eigen;
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

typedef Matrix<double, Dynamic, Dynamic> MatrixXd;

void initialize(MatrixXd& a, MatrixXd& b, MatrixXd& c, const size_t n)
{
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
        {
            a(i, j) = 3 * (i + 1) + j;
            b(i, j) = 2 * j + (i + 1);
            c(i, j) = 0;
        }
}

int main(int argc, char** argv)
{
    if (argc > 1 )
    {
        std::size_t const n = atoi(argv[1]);
        std::size_t const reps = atoi(argv[2]);
        MatrixXd a(n, n);
        MatrixXd b(n, n);
        MatrixXd c(n, n);

        initialize(a, b, c, n);

        for (std::size_t i = 0; i < reps; ++i)
        {
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            c = a * b;
            high_resolution_clock::time_point t2 = high_resolution_clock::now();

            microseconds elapsed = duration_cast<microseconds>(t2-t1);
            cout<<"matrix size: "<<n<<" finished in "<<elapsed.count()<<" microseconds"<<endl;
        }

    }
    return 0;
}
