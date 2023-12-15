#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    // Считываем поле с монетами и разбойниками
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    // Инициализация массива для хранения наибольшей суммы монет до каждой клетки
    vector<vector<int>> dp(N, vector<int>(M));
    // Инициализируем начальное значение
    dp[0][0] = grid[0][0];

    // Заполняем верхнюю строку
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    // Заполняем левый столбец
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    // Находим наибольшую сумму монет для каждой клетки
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    // Восстанавливаем путь
    int i = N - 1, j = M - 1;
    string path = "";
    while (i > 0 || j > 0) {
        if (i == 0) {
            path = "R" + path;
            j--;
        } else if (j == 0) {
            path = "D" + path;
            i--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                path = "D" + path;
                i--;
            } else {
                path = "R" + path;
                j--;
            }
        }
    }

    // Выводим результат
    cout << dp[N - 1][M - 1] << endl;
    cout << path << endl;

    return 0;
}