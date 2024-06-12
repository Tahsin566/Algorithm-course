
#include <bits/stdc++.h>

using namespace std;

int knapsack(int p[], int w[], int W, int n) {

  int dp[n + 1][W + 1];
  memset(dp, 0, sizeof(dp)); //Initializing the array with 0

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= W; j++) {
      if (i == 0 || j == 0) {  //For filling first row and first column
        dp[i][j] = 0;
      } else if (w[i - 1] <= j) {

        dp[i][j] = max(p[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
        //max returns maximum of the two values

      } else {
        dp[i][j] = dp[i - 1][j]; //Initialize the value at top to the index dp[i][j]
      }
    }
  }

  return dp[n][W];
}

int main() {
  int W = 8;
  int p[] = {1, 2, 5, 6};
  int w[] = {2, 3, 4, 5};

  int n = sizeof(p) / sizeof(p[0]);

  int ans = knapsack(p, w, W, n);
  cout << ans << endl;

  return 0;
}