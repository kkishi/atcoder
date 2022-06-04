#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

void Main() {
  ints(n, q);
  V<int> a(n), b(n);
  cin >> a >> b;
  auto f = [&](const V<int>& v) {
    SegmentTree<int> t(
        n - 1, [](int a, int b) { return gcd(a, b); }, 0);
    rep(i, n - 1) t.Set(i, abs(v[i + 1] - v[i]));
    return t;
  };
  auto A = f(a);
  auto B = f(b);
  rep(q) {
    ints(h1, h2, w1, w2);
    int ga = A.Aggregate(h1 - 1, h2 - 1);
    int gb = B.Aggregate(w1 - 1, w2 - 1);
    int g = gcd(ga, gb);
    wt(gcd(g, a[h1 - 1] + b[w1 - 1]));
  }
}
