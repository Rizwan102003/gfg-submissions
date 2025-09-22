class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> left(n);
        stack<int> s1;
    for (int i = 0; i < n; ++i) {
        while (!s1.empty() && arr[s1.top()] >= arr[i]) {
            s1.pop();
        }
        left[i] = s1.empty() ? -1 : s1.top();
        s1.push(i);
    }
    vector<int> right(n);
    stack<int> s2;
    for (int i = n - 1; i >= 0; --i) {
        while (!s2.empty() && arr[s2.top()] >= arr[i]) {
            s2.pop();
        }
        right[i] = s2.empty() ? n : s2.top();
        s2.push(i);
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        int len = right[i] - left[i] - 1;
        if (len > 0) {
            ans[len - 1] = max(ans[len - 1], arr[i]);
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
    }
};