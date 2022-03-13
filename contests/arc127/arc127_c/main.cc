#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(x);
  V<int> v;
  rep(i, sz(x)) v.pb(x[i] - '0');
  reverse(v);
  auto sub = [](V<int>& v, int p) {
    rep(i, p, sz(v)) {
      if (v[i] == 0) {
        v[i] = 1;
      } else {
        v[i] = 0;
        break;
      }
    }
    while (v.back() == 0) v.pop_back();
  };
  sub(v, 0);
  string ans = "1";
  rrep(i, n) {
    if (v.empty()) break;
    bool gt = sz(v) >= i + 1;
    if (gt) {
      ans += '1';
      sub(v, i);
    } else {
      ans += '0';
      sub(v, 0);
    }
  }
  wt(ans);
}
