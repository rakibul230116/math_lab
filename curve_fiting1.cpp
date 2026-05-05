#include <iostream>
using namespace std;

int main() {
    int n;
    double x[10], y[10];
    double sumx=0, sumy=0, sumxy=0, sumx2=0;
    double a, b;

    cout << "Enter number of data: ";
    cin >> n;

    cout << "Enter x and y values:\n";
    for(int i=0; i<n; i++) {
        cin >> x[i] >> y[i];

        sumx += x[i];
        sumy += y[i];
        sumxy += x[i]*y[i];
        sumx2 += x[i]*x[i];
    }

    // Normal equations
    b = (n*sumxy - sumx*sumy) / (n*sumx2 - sumx*sumx);
    a = (sumy - b*sumx) / n;

    cout << "Equation of line: y = " << a << " + " << b << "x" << endl;

    return 0;
}
