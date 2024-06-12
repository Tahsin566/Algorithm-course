#include<bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();

    // Create a 2D array 
    int dp[n + 1][m + 1]; //since we have to iterate upto n row and m column

    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;   //for first row
    }

    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;   //for first column
    }

    // Fill DP array by trversing the array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; //If matches,add 1 with diagonal element
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
            }
        }
    }

    // Backtrack to get the LCS
    string lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        // if (word1[i - 1] == word2[j - 1]) {
        if (dp[i-1][j] == dp[i][j-1]) {
            lcs = word1[i - 1] + lcs;
            i--;      //Going diagonally in backtracking
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;   //Going upwards in backtracking
        } else {
            j--;   //Going downwards in backtrack
        }
    }

    return lcs;
}

int main() {
    string word1 = "abcde";
    string word2 = "bd";

    string lcs = longestCommonSubsequence(word1, word2);

    cout << "Longest Common Subsequence of " << word1 << " and " << word2 << " is: " << lcs << endl;

    return 0;
}
