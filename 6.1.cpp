#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int binarySearchClosest(const vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (right < 0) {
        return arr[left];
    } else if (left >= arr.size()) {
        return arr[right];
    } else {
        return abs(arr[left] - target) < abs(arr[right] - target) ? arr[left] : arr[right];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
    }

    int m;
    cin >> m;
    vector<int> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i];
    }

    for (int i = 0; i < m; ++i) {
        cout << binarySearchClosest(elements, queries[i]) << " ";
    }

    return 0;
}