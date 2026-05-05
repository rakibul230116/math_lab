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

    cout << "Enter a, b, n (n must be even): ";
    cin >> a >> b >> n;

    if(n % 2 != 0) {
        cout << "n must be even!" << endl;
        return 0;
    }

    h = (b - a) / n;

    sum = f(a) + f(b);

    for(int i = 1; i < n; i++) {
        if(i % 2 == 0)
            sum += 2 * f(a + i*h);
        else
            sum += 4 * f(a + i*h);
    }

    double I = (h/3) * sum;

    cout << "Integral = " << I << endl;

    return 0;
}
