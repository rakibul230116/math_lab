#include <iostream>
#include <cmath>
using namespace std;

// Example function: f(x) = x^2
double f(double x) {
    return x*x;
}

int main() {
    double a, b, h, sum;
    int n;

    cout << "Enter a, b, n: ";
    cin >> a >> b >> n;

    h = (b - a) / n;

    sum = f(a) + f(b);

    for(int i = 1; i < n; i++) {
        sum += 2 * f(a + i*h);
    }

    double I = (h/2) * sum;

    cout << "Integral = " << I << endl;

    return 0;
}
