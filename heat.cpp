#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nx, nt;
    double length, time, alpha;

    cout << "Enter length, time, alpha: ";
    cin >> length >> time >> alpha;

    cout << "Enter nx and nt: ";
    cin >> nx >> nt;

    double dx = length / nx;
    double dt = time / nt;

    double r = alpha * dt / (dx * dx);

    if(r > 0.5) {
        cout << "Warning: solution may be unstable (r > 0.5)\n";
    }

    vector<double> u(nx+1), new_u(nx+1);

    // Initial condition
    for(int i = 0; i <= nx; i++) {
        u[i] = 0;
    }

    // Boundary conditions
    u[0] = 100;
    u[nx] = 50;

    // Time stepping
    for(int t = 0; t < nt; t++) {

        new_u = u;

        for(int i = 1; i < nx; i++) {
            new_u[i] = u[i] + r * (u[i+1] - 2*u[i] + u[i-1]);
        }

        u = new_u;
    }

    cout << "\nFinal temperature distribution:\n";
    for(int i = 0; i <= nx; i++) {
        cout << "u[" << i << "] = " << u[i] << endl;
    }

    return 0;
}
