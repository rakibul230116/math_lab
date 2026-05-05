#include <iostream>
#include <cmath>
using namespace std;

// f(x) = x^3 - x - 2
double f(double x) {
    return x*x*x - x - 2;
}

int main() {
    double x0, x1, x2, tol;
    int max_iter;

    cout << "Enter first guess (x0): ";
    cin >> x0;

    cout << "Enter second guess (x1): ";
    cin >> x1;

    cout << "Enter tolerance: ";
    cin >> tol;

    cout << "Enter max iterations: ";
    cin >> max_iter;

    cout << "\nIter\t x\t\t f(x)\n";
    cout << "----------------------------------------\n";

    for (int i = 1; i <= max_iter; i++) {

        if (f(x1) - f(x0) == 0) {
            cout << "Division by zero!" << endl;
            return 0;
        }

        // Secant formula
        x2 = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0));

        cout << i << "\t " << x2 << "\t " << f(x2) << endl;

        if (fabs(x2 - x1) < tol) break;

        x0 = x1;
        x1 = x2;
    }

    cout << "----------------------------------------\n";
    cout << "Root = " << x2 << endl;

    return 0;
}
