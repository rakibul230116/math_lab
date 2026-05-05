#include <iostream>
#include <cmath>
using namespace std;

// Given differential equation
double f(double x, double y) {
    return x - y/(x*x + y*y);
}

int main() {
    double x0, y0, x_target, h;
    int iterations;

    cout << "Enter x0: ";
    cin >> x0;

    cout << "Enter y(x0): ";
    cin >> y0;

    cout << "Enter target x: ";
    cin >> x_target;

    cout << "Enter step size h: ";
    cin >> h;

    cout << "Enter iterations: ";
    cin >> iterations;

    double y = y0;

    for(int k = 1; k <= iterations; k++) {

        int n = (x_target - x0) / h;
        double sum = 0;

        for(int i = 0; i <= n; i++) {
            double xi = x0 + i*h;

            if(i == 0 || i == n)
                sum += f(xi, y);
            else
                sum += 2 * f(xi, y);
        }

        double new_y = y0 + (h/2) * sum;

        cout << "Iteration " << k << ": y(" << x_target << ") = " << new_y << endl;

        y = new_y;
    }

    cout << "\nFinal Answer: y(" << x_target << ") = " << y << endl;

    return 0;
}
