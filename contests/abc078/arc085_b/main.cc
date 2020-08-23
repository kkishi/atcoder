#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, z, w);
  V<int> a(n);
  cin >> a;
  VV<optional<int>> dp(2, V<optional<int>>(n + 1));
  wt(Fix([&](auto rec, int i, bool x) -> int {
    optional<int>& d = dp[x][i];
    if (!d) {
      V<int> v;
      for (int j = i + 1; j < n; ++j) {
        v.push_back(rec(j, !x));
      }
      int op = (i == 0 ? (x ? w : z) : a[i - 1]);
      v.push_back(abs(op - a[n - 1]));
      if (x) {
        d = *max_element(all(v));
      } else {
        d = *min_element(all(v));
      }
    }
    return *d;
  })(0, true));
}
