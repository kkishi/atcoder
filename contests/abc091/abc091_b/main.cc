#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  ints(m);
  V<string> t(m);
  cin >> t;
  int ans = 0;
  rep(i, n) chmax(ans, count(all(s), s[i]) - count(all(t), s[i]));
  wt(ans);
}
