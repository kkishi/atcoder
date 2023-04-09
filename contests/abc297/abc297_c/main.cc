#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  rep(i, h) {
    rep(j, w - 1) {
      if (s[i][j] == 'T' && s[i][j + 1] == 'T') {
        s[i][j] = 'P';
        s[i][j + 1] = 'C';
      }
    }
  }
  each(e, s) wt(e);
}
