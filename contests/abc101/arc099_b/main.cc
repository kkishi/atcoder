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

int keta(int x) {
  int ret = 0;
  while (x) {
    ++ret;
    x /= 10;
  }
  return ret;
}

int pow10(int x) {
  int ret = 1;
  rep(x) ret *= 10;
  return ret;
}

void Main() {
  int j = 999999999999999999LL, sj = 1;
  V<int> ans;
  for (int i = 999999999999999999LL; i >= 1;) {
    int si = s(i);
    if (i * sj <= j * si) {
      ans.pb(i);
      j = i;
      sj = si;
    }
    int k = keta(i);
    i -= pow10(max(0, k - 3));
  }
  reverse(ans);
  ints(k);
  rep(i, k) wt(ans[i]);
}
