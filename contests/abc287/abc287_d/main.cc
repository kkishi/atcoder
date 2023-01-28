#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  int n = sz(t);

  V<bool> l(n + 1);
  l[0] = true;
  rep(i, n) l[i + 1] = l[i] && (s[i] == t[i] || s[i] == '?' || t[i] == '?');

  reverse(s);
  reverse(t);

  V<bool> r(n + 1);
  r[0] = true;
  rep(i, n) r[i + 1] = r[i] && (s[i] == t[i] || s[i] == '?' || t[i] == '?');

  rep(i, n + 1) wt(l[i] && r[n - i]);
}
