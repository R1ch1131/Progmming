#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, vector<int>> findLongestIncreasingSubsequence(const vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxIndex = distance(dp.begin(), max_element(dp.begin(), dp.end()));
    int maxLength = dp[maxIndex];

    vector<int> result;
    result.push_back(arr[maxIndex]);

    int currentLength = maxLength;
    for (int i = maxIndex - 1; i >= 0; --i) {
        if (arr[i] < arr[maxIndex] && dp[i] == currentLength - 1) {
            result.push_back(arr[i]);
            currentLength -= 1;
            maxIndex = i;
        }
    }

    reverse(result.begin(), result.end());

    return make_pair(maxLength, result);
}

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    auto result = findLongestIncreasingSubsequence(sequence);
    cout << result.first << "\n";
    for (int i = 0; i < result.second.size(); ++i) {
        cout << result.second[i] << " ";
    }
    cout << "\n";

    return 0;
}