#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  cout << setprecision(8);
  while (true) {
    ints(n);
    if (n == 0) break;
    V<int> x(n);
    cin >> x;
    wt(BinarySearch<double>(10000000, 0, [&](double v) {
      V<double> dp(n);
      rrep(i, n - 1) {
        if (x[i] == -1) {
          dp[i] = v;
        } else if (x[i] == 0) {
          double sum = 0;
          rep(j, 1, 7) {
            int k = i + j;
            if (k < n) {
              sum += dp[k];
            }
          }
          dp[i] = 1 + sum / 6;
        } else {
          int j = i + x[i];
          if (j < n) {
            dp[i] = dp[j];
          }
        }
      }
      return v > dp[0];
    }));
  }
}
