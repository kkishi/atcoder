#include <bits/stdc++.h>

#include "atcoder.h"

int Naive(int n, int k) {
  int ans = 0;
  rep(i, 1, n + 1) {
    string s = to_string(i);
    int p = 1;
    each(e, s) p *= e - '0';
    if (p <= k) {
      ++ans;
      dbg(i);
    }
  }
  return ans;
}

void Main() {
  ints(n, k);
  wt(Naive(n, k));
}
