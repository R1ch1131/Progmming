#include <iostream>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int findMinSquareSide(int n, int w, int h) {
    int left = max(w, h);
    int right = left * n;

    while (right - left > 1) {
        int mid = (right + left) / 2;
        int res = (mid / w) * (mid / h);
        if (res < n) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return right;
}

int main() {
    int n, w, h;
    cin >> n >> w >> h;

    int result = findMinSquareSide(n, w, h);
    cout << result << endl;

    return 0;
}