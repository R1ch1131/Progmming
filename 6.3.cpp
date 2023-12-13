#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double findRoot(double a) {
    double left = 1.0;
    double right = 10.0; 

    while (right - left > 1e-6) { 
        double mid = (left + right) / 2.0;
        if (mid * mid - mid + sqrt(mid) > a) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
}

int main() {
    double a;
    cin >> a;
    
    double result = findRoot(a);

    cout << fixed << setprecision(6) << result << endl;

    return 0;
}