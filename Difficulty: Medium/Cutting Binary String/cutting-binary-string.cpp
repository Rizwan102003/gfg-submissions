class Solution {
  public:
    int solve(int i,int n,string &s,unordered_set<int>&st,vector<int>&dp){
      if(i==n){
          return 0;
      }
      if(dp[i]!=-1)return dp[i];
      int minCount=n+1;
      int num=0;
      for(int j=i;j<n;j++){
        // num= num* 2 + (s[j]-'0');
        num=(num<<1) + (s[j]-'0');
          if(s[i]=='1' && st.count(num)){
              minCount=min(minCount,1+solve(j+1,n,s,st,dp));
          }
      }
      return dp[i] =minCount;
  }
    int cuts(string s) {
        // code here
        int n=s.size();
        unordered_set<int>st;
        vector<int>dp(n+1,-1);
        for(int num=1;num<=1e9;num=num*5)st.insert(num);
        if(s[0]=='0')return -1;
        int ans= solve(0,n,s,st,dp);
        return ans>n?-1:ans;
    }
};