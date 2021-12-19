#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    ints(n, m);
    V<pair<int, int>> a(m), b(m);
    cin >> a >> b;
    each(e, a) if (e.first > e.second) swap(e.first, e.second);
    sort(all(a));
    V<int> idx(n);
    iota(all(idx), 0);
    do {
      V<pair<int, int>> c;
      rep(i, m) c.eb(idx[b[i].first - 1] + 1, idx[b[i].second - 1] + 1);
      each(e, c) if (e.first > e.second) swap(e.first, e.second);
      sort(all(c));
      if (a == c) return true;
    } while (next_permutation(all(idx)));
    return false;
  }());
}
