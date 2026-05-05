#include <iostream>
using namespace std;

int main() {
    int n;
    double x[20], y[20][20];
    double value, u, h;

    cout << "Enter number of data points: ";
    cin >> n;

    cout << "Enter x and y values:\n";
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i][0];
    }

    // Central difference table (same as forward but used centrally)
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < n - j; i++) {
            y[i][j] = y[i+1][j-1] - y[i][j-1];
        }
    }

    cout << "Enter value of x to find y: ";
    cin >> value;

    h = x[1] - x[0];
    int mid = n / 2;
    u = (value - x[mid]) / h;

    double sum = y[mid][0];
    double term = 1;

    for(int i = 1; i < n; i++) {
        term = term * (u - (i-1)) / i;
        sum += term * y[mid][i];
    }

    cout << "Interpolated value = " << sum << endl;

    return 0;
}
