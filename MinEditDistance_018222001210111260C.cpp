
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int minEditDistance(string word1, string word2) {
    int n = word2.length();
    int m = word1.length();

    // Create a 2D DP array 
    int dp[n + 1][m + 1];  // We have to iterate up to n m index

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {       
            dp[0][j] = j;  // for filling the first row
            dp[i][0] = i;  // for filling first column
        }
    }

    // Fill DP array by traversing up to dp[n][m]
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1]==word2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1];   // Diagonal traversal
            } else {
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
            // Takes minimum of values that are at the up, left, or diagonal of the dp[i][j]
        }
    }

    
    return dp[n][m]; // Returns the minimum edit distance
}

int main() {
    string word1 = "abcdef";
    string word2 = "ayced";

    int distance = minEditDistance(word1, word2);
    

    cout << "Minimum Edit Distance between " << word1 << " and " << word2 << " is: " << distance << endl;
    

    return 0;
}
