#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  strings(s);
  string ans = s;
  string t = s;
  sort(all(t));
  do {
    int ch = 0;
    rep(i, n) if (s[i] != t[i])++ ch;
    if (ch <= k) chmin(ans, t);
  } while (next_permutation(all(t)));
  wt(ans);
}
