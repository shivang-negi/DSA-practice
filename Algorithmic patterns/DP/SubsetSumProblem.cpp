#include<bits/stdc++.h>
using namespace std;

// Equal sum partition

bool helper(vector<int>&nums , int sum, int ind, vector<vector<int>>&memo) {
    if(sum==0) return true;
    else if(ind<0) return false;
    if(memo[ind][sum]!=-1) return memo[ind][sum];
    else if(nums[ind]>sum) return memo[ind][sum] = helper(nums,sum,ind-1,memo);
    else
        return memo[ind][sum] = helper(nums,sum,ind-1,memo) || helper(nums,sum-nums[ind],ind-1,memo); 
}

bool canPartition(vector<int> nums) {
    int sum = 0;
    for(int x:nums)
        sum+=x;
                                                
    if(sum & 1) return false;
    
    sum/=2;
    int n = nums.size();
    
    // Memoization:
    // vector<vector<int>> memo(n+1,vector<int>(sum+1,-1));
    // return helper(nums,sum, n-1,memo);
    
    bool dp[n+1][sum+1];
    
    dp[0][0] = true;
    
    for (int i = 1; i < n+1; i++) {
        dp[i][0] = true;
    }
    for (int j = 1; j < sum+1; j++) {
        dp[0][j] = false;
    }
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=sum;j++) {
            if(nums[i-1]<=j) 
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            else
                dp[i][j] = dp[i-1][j];
            }
        }
    return dp[n][sum];
}

int main() {
    cout<<canPartition({1,5,11,5});
    return 0;
}