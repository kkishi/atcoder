#include <bits/stdc++.h>

#include "atcoder.h"

char Solve(string s) {
  while (sz(s) > 1) {
    string ns;
    rep(i, sz(s) - 1) if (s[i] == 'A') ns += s[i + 1];
    rep(i, sz(s) - 1) if (s[i] == 'B') ns += s[i + 1];
    swap(s, ns);
  }
  return s[0];
}

void Main() {
  string s;
  Fix([&](auto rec, int depth) -> void {
    dbg(s, Solve(s));
    if (depth < 5) {
      rep(i, 2) {
        s += (char)('A' + i);
        rec(depth + 1);
        s.pop_back();
      }
    }
  })(0);
}
