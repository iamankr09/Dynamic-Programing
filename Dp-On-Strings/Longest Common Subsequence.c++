class Solution {
public:
 // Memoization
    int Lcs(string &s1 , string &s2 , int idx1 , int idx2 ,vector<vector<int>> &dp){
         if(idx1 == 0 or idx2 == 0) return 0;
         if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1-1] == s2[idx2-1]){
            return dp[idx1][idx2] = 1 + Lcs(s1 , s2 , idx1-1 , idx2-1 , dp);
        }
        else{
            int option1 = 0 + Lcs(s1 ,s2 , idx1-1 , idx2 , dp);
            int option2 = 0 + Lcs(s1 , s2 , idx1 , idx2-1, dp);
            return  dp[idx1][idx2] = max(option1 , option2);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        // vector<vector<int>> dp(m+1 , vector<int>(n+1, -1));
        // return Lcs(text1 , text2 , m , n , dp);

   /* 
      // Tabulation
        vector<vector<int>> dp(m+1 , vector<int>(n+1, 0));
        for(int i = 0 ; i <= m ; i++) dp[i][0] = 0;
        for(int j = 0 ; j <= n ; j++) dp[0][j] = 0;

        for(int idx1 = 1 ; idx1 <= m ; idx1++){
           for(int idx2 = 1 ; idx2 <= n ; idx2++){
                if(text1[idx1-1] == text2[idx2-1]){
                     dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                }
                else{
                    int option1 = 0 + dp[idx1-1][idx2];
                    int option2 = 0 +  dp[idx1][idx2-1];
                    dp[idx1][idx2] = max(option1 , option2);
                }
           }
        }

        return dp[m][n];

     */   
     
     // Space Optimization
       vector<int> prev(n+1 , 0);
       
        for(int j = 0 ; j <= n ; j++) prev[j] = 0;

        for(int idx1 = 1 ; idx1 <= m ; idx1++){
             vector<int> curr(n+1 ,0);
           for(int idx2 = 1 ; idx2 <= n ; idx2++){
                if(text1[idx1-1] == text2[idx2-1]){
                     curr[idx2] = 1 + prev[idx2-1];
                }
                else{
                    int option1 = 0 + prev[idx2];
                    int option2 = 0 +  curr[idx2-1];
                    curr[idx2] = max(option1 , option2);
                }
           }

           prev = curr;
        }

        return prev[n];



    }
};
