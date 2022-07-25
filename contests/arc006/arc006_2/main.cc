#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l);
  V<string> lines(l);
  getline(cin, lines[0]);  // Skip the first newline character.
  each(e, lines) getline(cin, e);
  string last;
  getline(cin, last);
  int ans;
  rep(i, n) if (last[i * 2] == 'o') ans = i;
  rrep(i, l) {
    rep(j, n - 1) if (lines[i][1 + j * 2] == '-') {
      int x = j, y = j + 1;
      if (x == ans || y == ans) {
        ans = x + y - ans;
      }
    }
  }
  wt(ans + 1);
}
