#include <iostream>
#include <vector>

using namespace std;

vector<int> readInput(int N) {
    vector<int> input(N);
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    return input;
}

vector<int> countOccurrences(const vector<int>& input) {
    vector<int> count(128, 0);
    for (int i = 0; i < input.size(); i++) {
        count[input[i]]++;
    }
    return count;
}

void printSortedOutput(const vector<int>& count) {
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < count[i]; j++) {
            cout << i << " ";
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> input = readInput(N);
    vector<int> count = countOccurrences(input);
    printSortedOutput(count);

    return 0;
}