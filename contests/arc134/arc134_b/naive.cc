#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  string ans = s;
  Fix([&](auto rec, int l, int r) {
    if (l >= r) {
      chmin(ans, s);
      return;
    }
    swap(s[l], s[r]);
    rec(l + 1, r - 1);
    swap(s[l], s[r]);
    rec(l + 1, r);
    rec(l, r - 1);
  })(0, n - 1);
  wt(ans);
}
