#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    strings(s);
    V<int> cnt(7);
    map<int, int> idx = {{7, 0}, {4, 1}, {8, 2}, {2, 2}, {5, 3},
                         {1, 3}, {9, 4}, {3, 4}, {6, 5}, {10, 6}};
    rep(i, 10) if (s[i] == '1')++ cnt[idx[i + 1]];
    if (s[0] == '0') {
      rep(i, 7) rep(j, i + 1, 7) rep(k, j + 1, 7) {
        if (cnt[i] && !cnt[j] && cnt[k]) return true;
      }
    }
    return false;
  }());
}
