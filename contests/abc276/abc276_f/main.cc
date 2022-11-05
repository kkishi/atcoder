#include <bits/stdc++.h>

#include "add_segment_tree.h"
#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int N = 200000;
  AddSegmentTree<mint> cnt(N + 1), sum(N + 1);
  mint ans = 0;
  rep(i, n) {
    mint l = cnt.Aggregate(0, a[i]);
    mint h = sum.Aggregate(a[i], N + 1);
    mint x = l * a[i] + h;
    ans += x * 2 + a[i];
    wt(ans / (i + 1) / (i + 1));
    cnt.Set(a[i], cnt.Get(a[i]) + 1);
    sum.Set(a[i], sum.Get(a[i]) + a[i]);
  }
}
