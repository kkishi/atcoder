#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> v;
  for (int N = n; N;) {
    int i = 1;
    while ((i + 1) * (i + 2) / 2 <= N) ++i;
    v.pb(i);
    N -= i * (i + 1) / 2;
  }
  string ans;
  int rem = 1;
  each(e, v) {
    if (!ans.empty()) {
      ans += '0' + rem;
    }
    ans += string(e, '7');
    rep(e + 1) { rem = rem * 10 % 7; }
  }
  wt(ans);
}
