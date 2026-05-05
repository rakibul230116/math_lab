#include <iostream>
#include <cmath>
using namespace std;

// Differential equation
double f(double x, double y) {
    return x - y/(x*x + y*y);
}

int main() {
    double x0, y0, h, x_target;

    cout << "Enter x0: ";
    cin >> x0;

    cout << "Enter y0: ";
    cin >> y0;

    cout << "Enter step size h: ";
    cin >> h;

    cout << "Enter target x: ";
    cin >> x_target;

    double x = x0;
    double y = y0;

    cout << "\nStep\t x\t\t y\n";
    cout << "----------------------------\n";

    while(x < x_target) {

        cout << x << "\t " << y << endl;

        y = y + h * f(x, y);   // Euler update
        x = x + h;
    }

    cout << "----------------------------\n";
    cout << "Final y(" << x_target << ") = " << y << endl;

    return 0;
}
