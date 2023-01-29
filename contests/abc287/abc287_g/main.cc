#include <bits/stdc++.h>

#include "add_segment_tree.h"
#include "atcoder.h"
#include "binary_search.h"
#include "compressor.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  ints(q);
  V<int> t(q), x(q), y(q);
  rep(i, q) {
    cin >> t[i] >> x[i];
    if (t[i] <= 2) {
      --x[i];
      cin >> y[i];
    }
  }

  V<int> vs;
  rep(i, n) vs.pb(a[i]);
  rep(i, q) if (t[i] == 1) vs.pb(y[i]);

  Compressor c(vs);
  int N = sz(c.coord);
  AddSegmentTree<int> cnt(N), val(N);
  auto add = [&](AddSegmentTree<int>& t, int v, int x) { t.Add(c(v), x); };
  rep(i, n) {
    add(cnt, a[i], b[i]);
    add(val, a[i], a[i] * b[i]);
  }
  rep(i, q) {
    if (t[i] == 1) {
      int& A = a[x[i]];
      const int& B = b[x[i]];
      add(cnt, A, -B);
      add(val, A, -A * B);
      A = y[i];
      add(cnt, A, B);
      add(val, A, A * B);
    } else if (t[i] == 2) {
      const int& A = a[x[i]];
      int& B = b[x[i]];
      int d = y[i] - B;
      B = y[i];
      add(cnt, A, d);
      add(val, A, d * A);
    } else {
      int tot = cnt.Aggregate(0, N);
      if (tot < x[i]) {
        wt(-1);
        continue;
      }
      int I = BinarySearch<int>(
          N, -1, [&](int I) { return cnt.Aggregate(I, N) <= x[i]; });
      int ans = val.Aggregate(I, N);
      int C = cnt.Aggregate(I, N);
      if (C < x[i]) {
        ans += (x[i] - C) * c.coord[I - 1];
      }
      wt(ans);
    }
  }
}
