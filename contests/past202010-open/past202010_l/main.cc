#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> h(n);
  cin >> h;
  map<int, int> oes, eos;
  rep(i, n - 1)(even(i) ? oes : eos)[h[i + 1] - h[i]]++;
  int oe = 0;
  rep(q) {
    ints(t);
    if (t == 1) {
      ints(v);
      oe -= v;
    } else if (t == 2) {
      ints(v);
      oe += v;
    } else {
      ints(u, v);
      --u;
      if (u + 1 < n) {
        int x = h[u + 1] - h[u];
        map<int, int>& m = even(u) ? oes : eos;
        --m[x];
        ++m[x - v];
      }
      if (u - 1 >= 0) {
        int x = h[u] - h[u - 1];
        map<int, int>& m = even(u - 1) ? oes : eos;
        --m[x];
        ++m[x + v];
      }
      h[u] += v;
    }
    wt(oes[-oe] + eos[oe]);
  }
}
