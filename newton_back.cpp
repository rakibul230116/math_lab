#include <iostream>
using namespace std;

int main() {
    int n;
    double x[10], y[10][10], value, u, h, sum;

    cout << "Enter number of data points: ";
    cin >> n;

    cout << "Enter x and y values:\n";
    for(int i=0; i<n; i++) {
        cin >> x[i] >> y[i][0];
    }

    // Create backward difference table
    for(int j=1; j<n; j++) {
        for(int i=n-1; i>=j; i--) {
            y[i][j] = y[i][j-1] - y[i-1][j-1];
        }
    }

    cout << "Enter value of x to find y: ";
    cin >> value;

    h = x[1] - x[0];
    u = (value - x[n-1]) / h;

    sum = y[n-1][0];
    double term = 1;

    for(int i=1; i<n; i++) {
        term = term * (u + (i-1)) / i;
        sum = sum + term * y[n-1][i];
    }

    cout << "Interpolated value = " << sum << endl;

    return 0;
}
