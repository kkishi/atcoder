#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b);
  strings(s);
  int ans = big;
  rep(i, n) {
    string t = s.substr(i) + s.substr(0, i);
    int cost = i * a;
    rep(i, n / 2) {
      if (t[i] != t[n - 1 - i]) {
        cost += b;
      }
    }
    chmin(ans, cost);
  }
  wt(ans);
}
