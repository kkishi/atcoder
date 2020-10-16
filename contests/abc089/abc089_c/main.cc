#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  map<char, int> m;
  rep(i, n)++ m[s[i][0]];
  string c = "MARCH";
  int ans = 0;
  rep(i, c.size()) rep(j, i) rep(k, j) ans += m[c[i]] * m[c[j]] * m[c[k]];
  wt(ans);
}
