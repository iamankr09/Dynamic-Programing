#include <bits/stdc++.h>
using namespace std;
int LongestCommonSubequence(string &s1 , string &s2 , int m , int n ,vector<vector<int>> &dp ){
      
      for(int i = 0 ; i <= m ; i++) dp[i][0] = 0;
      for(int j = 0 ; j <= n ; j++) dp[0][j] = 0;
      for(int i = 1 ; i <= m ; i++){
          for(int j = 1 ; j <= n ; j++){
              if(s1[i-1] == s2[j-1]){
                  dp[i][j] = 1 + dp[i-1][j-1];
              }
              else{
                  dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
              }
          }
      }
      
      return dp[m][n];
}
string Print_LongestCommonSubsequence(string &s1 , string &s2){
    int m =s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
    int maxLen = LongestCommonSubequence(s1 , s2 , m , n , dp);
    
    // traverse over the filled dp matrix and generate the Lcs
      string ans;
      for(int i = 0 ; i < maxLen ; i++){
           ans.push_back('&');
      }
      int i = m , j = n;
      int index = maxLen-1;
      while(i > 0 && j >0 ){
          if(s1[i-1] == s2[j-1]){
              ans[index] = s1[i-1];
              i--; j--;
              index--;
          }
          else if(dp[i-1][j] > dp[i][j-1]){
               i--;
          }
          else{
               j--;
          }
      }
      
      return ans;
}
int main()
{
    string s1;
      cin>>s1;
    string s2;
      cin>>s2;
    string ans = Print_LongestCommonSubsequence(s1 , s2);
    cout<<ans<<endl;

    return 0;
}
