class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        // code here
        multiset<pair<int, int>> st;
        for(auto x: arr) {
            if(st.lower_bound({x-1, INT_MIN}) == st.end()) {
                st.insert({x, 1});
            } else {
                auto top = st.lower_bound({x-1, INT_MIN});
                if(top -> first != x-1) {
                    st.insert({x, 1});
                } else {
                    st.erase(top);
                    st.insert({x, top -> second+1});
                }
            }
        }
        
        while(!st.empty()) {
            pair<int, int> top = *st.begin();
            if(top.second < k)  
                return false;
            st.erase(st.begin());
        }
        return true;
    }
};
