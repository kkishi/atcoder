#include <bits/stdc++.h>

#include <atcoder/segtree>

#include "atcoder.h"
#include "binary_search.h"
// #include "segment_tree.h"

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

void Main() {
  ints(n, l);
  V<int> a(n);
  cin >> a;
  V<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];
  wt(BinarySearch<int>(0, l + 1, [&](int x) {
    // SegmentTree<int> t(n + 1, [](int a, int b) { return max(a, b); });
    atcoder::segtree<int, op, e> t(n + 1);
    int lo = 0, hi = 0;
    rep(i, n) {
      while (s[i + 1] - s[lo] > l) ++lo;
      while (s[i + 1] - s[hi] >= x) ++hi;
      if (lo == 0) {
        // t.Set(i + 1, s[i + 1]);
        t.set(i + 1, s[i + 1]);
      } else {
        // t.Set(i + 1, t.Aggregate(lo, hi));
        t.set(i + 1, t.prod(lo, hi));
      }
    }
    // return t.Get(n) >= x;
    return t.prod(n, n + 1) >= x;
  }));
}
