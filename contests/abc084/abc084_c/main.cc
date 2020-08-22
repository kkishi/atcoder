#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  V<int> c(n - 1), s(n - 1), f(n - 1);
  rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];
  V<int> ans(n - 1);
  rrep(i, n - 1) {
    int t = 0;
    rep(j, i, n - 1) {
      chmax(t, s[j]);
      if (int m = t % f[j]; m != 0) {
        t += f[j] - m;
      }
      t += c[j];
    }
    ans[i] = t;
  }
  rep(i, n - 1) wt(ans[i]);
  wt(0);
}
