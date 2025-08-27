class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size();
        int count = 0;
        sort(arr.begin(), arr.end());
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int sum = arr[i] + arr[j];
                int index = lower_bound(arr.begin()+j+1, arr.end(), sum) - arr.begin();
                count += (index-j-1);
            }
        }
        
        return count;
    }
};
