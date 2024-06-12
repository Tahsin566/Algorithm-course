
#include <bits/stdc++.h>

using namespace std;
int coin_change_ways(int coins[], int W, int n)
{

    int dp[n + 1][W + 1]; // Since we have to iterate upto n W index
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1; // for initializing at first column
            }
            else if (i == 0)
            {
                dp[i][j] = 0; // for first row
            }
            else if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j]; // Initailize the value at top to dp[i][j]
        }
    }

    return dp[n][W];
}

int main()
{

    int coins[] = {2, 3, 5, 20};
    int W = 7;

    int n = sizeof(coins) / sizeof(coins[0]);
    int ans = coin_change_ways(coins, W, n);

    cout << ans << endl;

    return 0;
}
