class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
         vector<string> ans;
        for(int i = 1 ;i<=n;i++)
        {
            int len = (int)(log2(i));
            string x = bitset<64>(i).to_string().substr(64-len-1);
            ans.push_back(x);
        }
        return ans;
    }
};