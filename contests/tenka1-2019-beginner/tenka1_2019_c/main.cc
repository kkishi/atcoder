#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  int ans = n;
  V<int> w(n + 1);
  rep(i, n) w[i + 1] = w[i] + (s[i] == '.');
  rep(i, n + 1) {
    int tw = i - w[i];     // towhite(0, i)
    int tb = w[n] - w[i];  // toblack(i, n)
    chmin(ans, tw + tb);
  }
  wt(ans);
}
