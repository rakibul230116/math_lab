#include <iostream>
#include <cmath>
using namespace std;

// f(x) = x^3 - x - 2
double f(double x) {
    return x*x*x - x - 2;
}

// f'(x) = derivative = 3x^2 - 1
double df(double x) {
    return 3*x*x - 1;
}

int main() {
    double x0, x1, tol;
    int max_iter;

    cout << "Enter initial guess: ";
    cin >> x0;

    cout << "Enter tolerance: ";
    cin >> tol;

    cout << "Enter max iterations: ";
    cin >> max_iter;

    cout << "\nIter\t x\t\t f(x)\n";
    cout << "----------------------------------------\n";

    for (int i = 1; i <= max_iter; i++) {
        if (df(x0) == 0) {
            cout << "Derivative zero! Stop." << endl;
            return 0;
        }

        x1 = x0 - f(x0) / df(x0);

        cout << i << "\t " << x1 << "\t " << f(x1) << endl;

        if (fabs(x1 - x0) < tol) break;

        x0 = x1;
    }

    cout << "----------------------------------------\n";
    cout << "Root = " << x1 << endl;

    return 0;
}
