class Solution {
public:
    // int find(vector<vector<int>> &arr,int i,int j,int nue,vector<vector<vector<int>>>&dp){

    //     int n = arr.size(),m = arr[0].size();
    //     if(i == n-1 && j == m-1){
    //         if(arr[i][j] < 0 && nue < 2){
    //             return 0;
    //         }
    //         return arr[i][j];
    //     }
    //     if(i >= n || j >= m ){
    //         return INT_MIN;
    //     }

    //     if(dp[i][j][nue] != -1){
    //         return dp[i][j][nue];
    //     }

    //     int take = arr[i][j] + max(find(arr,i+1,j,nue,dp),find(arr,i,j+1,nue,dp));
    //     int skip = INT_MIN;

    //     if(arr[i][j] < 0 && nue < 2){
    //         skip = max(find(arr,i+1,j,nue+1,dp),find(arr,i,j+1,nue+1,dp));
    //     }

    //     return dp[i][j][nue] = max(skip,take);
    // }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(),m = coins[0].size();
        vector dp(n, vector(m, vector<int>(3,-1e9)));
        dp[0][0][2] = dp[0][0][1] = 0;
        dp[0][0][0] = coins[0][0];

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int k = 0;k<3;k++){
                    if(i) dp[i][j][k] = max(dp[i][j][k],coins[i][j] + dp[i-1][j][k]);
                    if(i && k) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]);
                    if(j) dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k] + coins[i][j]);
                    if(j && k) dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k-1]);
                }
            }
        }

        int ans = *max_element(dp[n-1][m-1].begin(),dp[n-1][m-1].end());
        return ans;
    }
};