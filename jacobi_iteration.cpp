
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a1,b1,c1,d1;
    double a2,b2,c2,d2;
    double a3,b3,c3,d3;

    double x=0, y=0, z=0;      // initial guess
    double x1, y1, z1;
    double tol;
    int max_iter;

    cout << "Enter coefficients:\n";

    cout << "a1 b1 c1 d1: ";
    cin >> a1 >> b1 >> c1 >> d1;

    cout << "a2 b2 c2 d2: ";
    cin >> a2 >> b2 >> c2 >> d2;

    cout << "a3 b3 c3 d3: ";
    cin >> a3 >> b3 >> c3 >> d3;

    cout << "Enter tolerance: ";
    cin >> tol;

    cout << "Enter max iterations: ";
    cin >> max_iter;

    cout << "\nIter\t x\t\t y\t\t z\n";
    cout << "-------------------------------------------\n";

    for(int i=1; i<=max_iter; i++) {

        // Jacobi formulas (use OLD values)
        x1 = (d1 - b1*y - c1*z) / a1;
        y1 = (d2 - a2*x - c2*z) / b2;
        z1 = (d3 - a3*x - b3*y) / c3;

        cout << i << "\t " << x1 << "\t " << y1 << "\t " << z1 << endl;

        // stopping condition
        if (fabs(x1-x)<tol && fabs(y1-y)<tol && fabs(z1-z)<tol)
            break;

        // update
        x = x1;
        y = y1;
        z = z1;
    }

    cout << "-------------------------------------------\n";
    cout << "Solution: x=" << x1 << " y=" << y1 << " z=" << z1 << endl;

    return 0;
}
