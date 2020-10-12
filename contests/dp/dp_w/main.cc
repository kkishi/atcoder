#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"
#include "modint.h"

using S = int;

S op(S a, S b) { return max(a, b); }

S e() { return numeric_limits<int>::min(); }

using F = int;

S mapping(F f, S x) { return f + x; }

F composition(F f, F g) { return f + g; }

F id() { return 0; }

// References:
// * https://www.youtube.com/watch?v=niACBP9pHZU
// * https://kyopro-friends.hatenablog.com/entry/2019/01/12/231106
void Main() {
  ints(n, m);

  map<int, V<pair<int, int>>> s;
  rep(m) {
    ints(l, r, a);
    s[r].emplace_back(l, a);
  }

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> tree(n + 1);
  tree.set(0, 0);
  rep(i, 1, n + 1) {
    int sum = 0;
    for (auto [_, a] : s[i]) sum += a;
    int x = tree.prod(0, i);
    tree.set(i, x + sum);
    for (auto [l, a] : s[i]) tree.apply(l, i, a);
  }
  wt(tree.prod(0, n + 1));
}
