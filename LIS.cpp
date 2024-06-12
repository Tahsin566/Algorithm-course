
#include <bits/stdc++.h>


using namespace std;

int longestIncreasingSubsequenceLength(int nums[], int n) {

    int dp[n],a[n];
    for (int i = 0; i <n; ++i) {  //Since every value itself is a subsequence,we put 1
                                   //in all indices
        dp[i] = 1;
        a[i]=0;
    }


    //loop for iterating the the array dp
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {   
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max = 0;
    for(int i = 0;i<n;i++){

        if(dp[i] > max){
            max = dp[i];
            a[i] = max;
            if(a[i]==max){
                cout<<nums[i]<<endl;
            }
        }
    }

    return dp[n-1];
}

int main() {
    int nums[] = {-5,-10,10, 22, 9, 33,21, 50, 41, 60,90};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << "Length of the longest increasing subsequence: " << longestIncreasingSubsequenceLength(nums, n) << endl;
    return 0;
}
