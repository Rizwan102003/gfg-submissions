class Solution {
  public:
    bool check(int mid, vector <int>& arr, int k){
        int n = arr.size();
        
        int sum = 0, cnt = 1;
        for(int i = 0; i < n; i++){
            if(cnt > k) return false;
            if(sum + arr[i] <= mid) sum += arr[i];
            else{
                if(arr[i] > mid) return false;
                sum = arr[i];
                cnt++;
            }
        }
        
        return (cnt <= k);
    }
  
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        int l = 1, r = sum;
        int ans = -1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(mid, arr, k)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        return ans;
    }
};