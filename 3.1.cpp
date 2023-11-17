#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> input(N);
    vector<int> count(128, 0);

    for (int i = 0; i < N; i++) {
        cin >> input[i];
        count[input[i]]++; 
    }

    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < count[i]; j++) {
            cout << i << " "; 
        }
    }

    return 0;
}