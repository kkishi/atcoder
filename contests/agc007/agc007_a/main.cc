#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> a(h);
  cin >> a;
  int r = 0, c = 0;
  while (true) {
    a[r][c] = '.';
    if (r + 1 < sz(a) && a[r + 1][c] == '#') {
      ++r;
      continue;
    }
    if (c + 1 < sz(a[r]) && a[r][c + 1] == '#') {
      ++c;
      continue;
    }
    break;
  }
  string ans = "Possible";
  each(s, a) each(c, s) if (c == '#') ans = "Impossible";
  wt(ans);
}
