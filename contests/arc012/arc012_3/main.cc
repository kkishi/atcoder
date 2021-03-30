#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  V<string> b(19);
  cin >> b;

  map<char, int> cnts;
  string kinds = "ox";
  for (char kind : kinds) {
    for (auto& bi : b) {
      for (char c : bi) {
        if (c == kind) ++cnts[kind];
      }
    }
  }

  if (cnts['o'] == 0 && cnts['x'] == 0) return true;

  char last;
  if (cnts['o'] == cnts['x']) {
    last = 'x';
  } else if (cnts['o'] == cnts['x'] + 1) {
    last = 'o';
  } else {
    return false;
  }

  rep(lr, 19) rep(lc, 19) if (char& c = b[lr][lc]; c == last) {
    c = '.';
    auto win = [&](char kind) {
      rep(r, 19) rep(c, 19) {
        auto check = [&](int dr, int dc) {
          auto at = [&](int r, int c) {
            if (!inside(r, c, 19, 19)) return '.';
            return b[r][c];
          };
          int cnt = 0;
          rep(i, 5) if (at(r + dr * i, c + dc * i) == kind)++ cnt;
          return cnt == 5;
        };
        if (check(0, 1) || check(1, 0) || check(1, 1) || check(1, -1))
          return true;
      }
      return false;
    };
    if (!win('o') && !win('x')) return true;
    c = last;
  }
  return false;
}

void Main() { wt(Solve() ? "YES" : "NO"); }
