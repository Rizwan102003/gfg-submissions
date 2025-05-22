class Solution {
  public:
    int LPS(string S, int n){
        string T=S;
        reverse(S.begin(),S.end());
        vector<int> curr(n+1,0), prev(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(S[i-1]==T[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return curr[n];
    }
  public:
    int minDeletions(string s) {
        int n=s.length();
        int lps_len=LPS(s,n);
        return n-lps_len;
    }
};