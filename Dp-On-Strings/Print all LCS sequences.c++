 // Print All Lcs Subsequence ---> Backtracking & Traversing on matrix
 
     int Lcs(string &s , string &t , int m , int n){
	            vector<vector<int>> dp(m+1 , vector<int>(n+1, 0));
                for(int i = 0 ; i <= m ; i++) dp[i][0] = 0;
                for(int j = 0 ; j <= n ; j++) dp[0][j] = 0;
        
                for(int idx1 = 1 ; idx1 <= m ; idx1++){
                   for(int idx2 = 1 ; idx2 <= n ; idx2++){
                        if(s[idx1-1] == t[idx2-1]){
                             dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                        }
                        else{
                            int option1 = 0 + dp[idx1-1][idx2];
                            int option2 = 0 +  dp[idx1][idx2-1];
                            dp[idx1][idx2] = max(option1 , option2);
                        }
                   }
                }
        
                return  dp[m][n];
	    }
	    void FindAllLcs(string &s1 , string &s2 , int i , int j , int len , string temp , vector<string> &ans , set<string> &st){
	            if(len == 0){
	                reverse(temp.begin() , temp.end());
	                if(st.find(temp) == st.end()){
	                    ans.push_back(temp);
	                    st.insert(temp);
	                }
	                return;
	            }
	            if(i == 0 || j == 0) return ;
	             for(int row = i ; row > 0  ; row--){
	                 for(int col = j ; col > 0 ; col--){
	                       if(s1[row-1] == s2[col-1]){
	                           temp.push_back(s1[row-1]);
	                           FindAllLcs(s1 , s2 , row-1 , col-1 , len-1 , temp , ans , st);
	                           temp.pop_back();
	                       }
	                 }
	             }
	    }
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		      int m = s.length();
		      int n = t.length();
		      int maxLength = Lcs(s,t,m,n); 
		      vector<string> ans;
		      set<string> st;
		      string temp = "";
		      FindAllLcs(s , t , m , n , maxLength , temp , ans , st);
		      sort(ans.begin() , ans.end());
		      return ans;
               
                
		}
