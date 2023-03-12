#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  cin >> a;
  V<int> v(h + w - 2);
  rep(i, w - 1) v[h - 1 + i] = 1;
  int ans = 0;
  do {
    set<int> seen = {a[0][0]};
    bool ok = true;
    int i = 0, j = 0;
    each(e, v) {
      if (e == 0) {
        ++i;
      } else {
        ++j;
      }
      if (!seen.insert(a[i][j]).second) ok = false;
    }
    if (ok) ++ans;

  } while (next_permutation(all(v)));
  wt(ans);
}
