#include <iostream>

using namespace std;

void countingSort(int arr[], int n) {
    int count[128] = {0}; 
    int output[n]; 

    for (int i = 0; i < n; i++) {
        count[arr[i]]++; 
    }

    for (int i = 1; i <= 127; i++) {
        count[i] += count[i-1];
    }

    for (int i = n-1; i >= 0; i--) {
        output[count[arr[i]]-1] = arr[i]; 
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    countingSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}