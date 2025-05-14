//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        string s1="1";
        while(--n)
        {
            int l=s1.length(), c=1;
            string s2="";
            for(int i=1; i<=l; i++)
            {
               if(s1[i] != s1[i-1])
               {
                   s2+= (c + '0');
                   s2+=s1[i-1];
                   c=1;
               }
               else
               {
                   c++;
               }
            }
            s1=s2;
            //cout<<s1<<"\n";
        }
        return s1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends