#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000; // assuming maximum length of the words



int minEditDistance(string word1, string word2) {

    int n = word2.length();
    int m = word1.length();

    int dp[n+1][m+1];

    // Initialize DP array
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (word1[j - 1] == word2[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    // Backtrack to find the operations
    int i = n, j = m;
    string operations[MAX];
    int opIndex = 0;

    while (i > 0 && j > 0) {
        if ( word1[j - 1] == word2[i - 1]) {
            i--;
            j--;
        } else if (dp[i][j] == dp[i - 1][j - 1] + 1) {
            operations[opIndex++] = "Replace '" + string(1, word1[j - 1]) + "' with '" + string(1, word2[i - 1]) + "'";
            // cout<<"Replace "<<word2[i-1]<<" with "<<word1[j-1]<<endl;
            i--;
            j--;
        } else if (dp[i][j] == dp[i - 1][j] + 1) {
            operations[opIndex++] = "Add '" ,word2[i - 1] ,"'";
            // cout<<"Add "<<word1[i-1]<<endl;
            i--;
        } else if (dp[i][j] == dp[i][j - 1] + 1) {
            operations[opIndex++] = "Delete '" + string(1, word1[j - 1]) + "'";
            // cout<<"Delete "<<word1[j-1]<<endl;
            j--;
        }
    }

    // Print operations in reverse order
    for (int k = opIndex-1 ; k >= 0; k--) {
        cout << operations[k] << endl;
    }

    return dp[n][m]; // Returns the minimum edit distance
}

int main() {

    string word1 = "abcdef";  //Convert string 1 to string 2
    string word2 = "ayced";

    int distance = minEditDistance(word1, word2);

    cout << "Minimum Edit Distance between " << word1 << " and " << word2 << " is: " << distance << endl;

    return 0;
}
