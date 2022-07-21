#include <bits/stdc++.h>

#include "atcoder.h"

int s(int x) {
  int ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

void Main() {
  ints(k);
  V<int> ans;
  int j = 10000000, sj = 1;
  rrep(i, 1, 10000000) {
    int si = s(i);
    if (i * sj <= j * si) {
      ans.pb(i);
      j = i;
      sj = si;
    }
  }
  reverse(ans);
  rep(i, k) wt(ans[i]);
}
