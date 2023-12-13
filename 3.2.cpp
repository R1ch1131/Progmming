#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getDigit(const string& num, int i) {
    if (i < num.length()) {
        return num[num.length() - 1 - i] - '0';
    }
    return 0;
}

void radixSort(vector<string>& arr, int n) {
    const int maxDigits = 20; 

    for (int digit = 0; digit < maxDigits; digit++) {
        vector<vector<string>> buckets(10);

        for (int i = 0; i < n; i++) {
            int currentDigit = getDigit(arr[i], digit);
            buckets[currentDigit].push_back(arr[i]);
        }

        int index = 0;
        for (auto& bucket : buckets) {
            for (string num : bucket) {
                arr[index++] = num;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    radixSort(numbers, n);

    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << endl;
    }

    return 0;
}