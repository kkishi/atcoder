#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    ints(n);
    V<string> s(n);
    cin >> s;
    rep(i, n) rep(j, n) {
      auto f = [&](int di, int dj) {
        int cnt = 0;
        rep(k, 6) {
          int I = i + di * k;
          int J = j + dj * k;
          if (!inside(I, J, n, n)) return false;
          if (s[I][J] == '.') ++cnt;
        }
        return cnt <= 2;
      };
      if (f(0, 1) || f(1, 1) || f(1, 0) || f(1, -1)) return true;
    }
    return false;
  }());
}
