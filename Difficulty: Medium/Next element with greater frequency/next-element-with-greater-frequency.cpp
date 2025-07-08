class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> NGE(n,0);
        int i = n-1;
        stack<pair<int,int>> st;
        unordered_map<int,int> mp;
        
        for(int j = 0; j < n; j++)
        {
            mp[arr[j]]++;
        }
        while(i >= 0)
        {
            while(st.size() and st.top().second <= mp[arr[i]])
            {
                st.pop();
            }
            
            NGE[i] = st.size() ? st.top().first : -1;
            st.push({arr[i], mp[arr[i]]});
            i--;
        }
        // code here
        return NGE;
    }
};
