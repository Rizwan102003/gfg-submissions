class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int ans = 0;
        int n = s.length();
        
        for(int i=0; i<n; i++){
            ans = ((ans*10) + (s[i]-'0')) % 13;
        }
        
        return ans == 0;
    }
};