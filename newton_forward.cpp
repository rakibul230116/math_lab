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

    // Create forward difference table
    for(int j=1; j<n; j++) {
        for(int i=0; i<n-j; i++) {
            y[i][j] = y[i+1][j-1] - y[i][j-1];
        }
    }

    cout << "Enter value of x to find y: ";
    cin >> value;

    h = x[1] - x[0];
    u = (value - x[0]) / h;

    sum = y[0][0];
    double term = 1;

    for(int i=1; i<n; i++) {
        term = term * (u - (i-1)) / i;
        sum = sum + term * y[0][i];
    }

    cout << "Interpolated value = " << sum << endl;

    return 0;
}
