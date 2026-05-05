#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a1,b1,c1,d1;
    double a2,b2,c2,d2;
    double a3,b3,c3,d3;

    double x=0, y=0, z=0;   // initial guess
    double x_old, y_old, z_old;
    double tol, w;
    int max_iter;

    cout << "Enter coefficients:\n";

    cout << "a1 b1 c1 d1: ";
    cin >> a1 >> b1 >> c1 >> d1;

    cout << "a2 b2 c2 d2: ";
    cin >> a2 >> b2 >> c2 >> d2;

    cout << "a3 b3 c3 d3: ";
    cin >> a3 >> b3 >> c3 >> d3;

    cout << "Enter relaxation factor (w): ";
    cin >> w;

    cout << "Enter tolerance: ";
    cin >> tol;

    cout << "Enter max iterations: ";
    cin >> max_iter;

    cout << "\nIter\t x\t\t y\t\t z\n";
    cout << "-------------------------------------------\n";

    for(int i=1; i<=max_iter; i++) {

        x_old = x;
        y_old = y;
        z_old = z;

        // Gauss-Seidel values
        double x_gs = (d1 - b1*y - c1*z) / a1;
        x = (1 - w)*x + w*x_gs;

        double y_gs = (d2 - a2*x - c2*z) / b2;
        y = (1 - w)*y + w*y_gs;

        double z_gs = (d3 - a3*x - b3*y) / c3;
        z = (1 - w)*z + w*z_gs;

        cout << i << "\t " << x << "\t " << y << "\t " << z << endl;

        // stopping condition
        if (fabs(x-x_old)<tol && fabs(y-y_old)<tol && fabs(z-z_old)<tol)
            break;
    }

    cout << "-------------------------------------------\n";
    cout << "Solution: x=" << x << " y=" << y << " z=" << z << endl;

    return 0;
}
