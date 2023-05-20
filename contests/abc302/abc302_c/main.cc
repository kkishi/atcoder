#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  ints(n, m);
  V<string> s(n);
  cin >> s;
  sort(s);
  do {
    bool ok = true;
    rep(i, n - 1) {
      int d = 0;
      rep(j, 8) if (s[i][j] != s[i + 1][j])++ d;
      if (d != 1) ok = false;
    }
    if (ok) return true;
  } while (next_permutation(all(s)));
  return false;
}
