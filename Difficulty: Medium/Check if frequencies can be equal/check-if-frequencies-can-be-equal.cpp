class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int> hash(26,0);
        for(auto it:s){
            hash[it-'a']++;
        }
        
        int freq = -1;
        bool f = true;
        
        for(int i=0;i<26;i++){
            if(hash[i] == 0) continue;
            if(freq == -1) freq = hash[i];
            else if(freq != hash[i]) f = false;
        }
        
        if(f) return true;
        
        for(int i=0;i<26;i++){
            if(hash[i] > 0){
                // cout << i << " " << hash[i] << endl;
                hash[i]--;
                int req = -1;
                bool flag = true;
                for(int j=0;j<26;j++){
                    if(hash[j] == 0) continue;
                    if(req == -1) req = hash[j];
                    else if(hash[j] != req) flag = false;
                }
                hash[i]++;
                if(flag) return true;
            }
        }
        return false;
    }
};