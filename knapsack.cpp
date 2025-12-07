#include <iostream>
#include <vector>
using namespace std;

int knapsackDP(vector<int>& values, vector<int>& weights, int W) {
    int n = values.size();
    vector<vector<int> > dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(
                    dp[i - 1][j],
                    values[i - 1] + dp[i - 1][j - weights[i - 1]]
                );
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) cin >> values[i];

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) cin >> weights[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Maximum value = " << knapsackDP(values, weights, W) << endl;

    return 0;
}
