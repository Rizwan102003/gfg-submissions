#include <bits/stdc++.h>
using namespace std;

class Solution {
  static constexpr int MAX = 10000;          // upper bound on arr[i]
  
  // helper: build smallest prime factor (spf) array
  vector<int> buildSPF() {
      vector<int> spf(MAX + 1);
      iota(spf.begin(), spf.end(), 0);       // initially spf[i] = i
      for (int i = 2; i * i <= MAX; ++i)
          if (spf[i] == i)                   // i is prime
              for (int j = i * i; j <= MAX; j += i)
                  if (spf[j] == j) spf[j] = i;
      return spf;
  }

  // helper: build Möbius function using spf[]
  vector<int> buildMobius(const vector<int>& spf) {
      vector<int> mu(MAX + 1, 1);            // mu[1] = 1
      mu[0] = 0;                             // unused index
      for (int i = 2; i <= MAX; ++i) {
          int x = i, last = -1, cnt = 0;
          bool square = false;
          while (x > 1) {                    // factor i
              int p = spf[x];
              x /= p;
              if (p == last) { square = true; break; }
              last = p;
              cnt++;
          }
          if (square) mu[i] = 0;
          else mu[i] = (cnt % 2 ? -1 : 1);
      }
      return mu;
  }
  
public:
    long long cntCoprime(vector<int>& arr) {
        // 1. frequency of exact values
        vector<int> cnt(MAX + 1, 0);
        for (int v : arr) ++cnt[v];
        
        // 2. cumulative frequency of multiples
        vector<int> freq(MAX + 1, 0);
        for (int d = 1; d <= MAX; ++d)
            for (int k = d; k <= MAX; k += d)
                freq[d] += cnt[k];
        
        // 3. Möbius array
        vector<int> spf = buildSPF();
        vector<int> mu  = buildMobius(spf);
        
        // 4. inclusion–exclusion sum
        long long ans = 0;
        for (int d = 1; d <= MAX; ++d) {
            int f = freq[d];
            if (f < 2 || mu[d] == 0) continue;
            long long pairs = 1LL * f * (f - 1) / 2;
            ans += 1LL * mu[d] * pairs;
        }
        return ans;                          // fits in 64‑bit; ≤ 5e7
    }
};