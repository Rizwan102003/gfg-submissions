//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int maxi = 0;
       unordered_map<int,int>mp;
       int count = 0;
       for(int i = 0;i<arr.size();i++){
           if(arr[i] <= k)count--;
           else count++;
           if(count > 0){
               maxi = max(maxi,i+1);
           }
           int y = count - 1;
           if(mp.find(y) != mp.end()){
               maxi = max(maxi,i-mp[y]);
           }
           if(mp.find(count) == mp.end()){
               mp[count] = i;
           }
       }
       
       return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends