#include <iostream>
#include <cmath>
using namespace std;

// f(x) = x^3 - x - 2
double f(double x) {
    return x*x*x - x - 2;
}

int main() {
    double a, b, c, tol;
    int max_iter;

    cout << "Enter a and b: ";
    cin >> a >> b;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval!" << endl;
        return 0;
    }

    cout << "Enter tolerance: ";
    cin >> tol;

    cout << "Enter max iterations: ";
    cin >> max_iter;

    cout << "\nIter\t a\t\t b\t\t c\t\t f(c)\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 1; i <= max_iter; i++) {
        c = (a + b) / 2;

        cout << i << "\t " << a << "\t " << b << "\t " << c << "\t " << f(c) << endl;

        if (fabs(f(c)) < tol) break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "------------------------------------------------------------\n";
    cout << "Root = " << c << endl;

    return 0;
}