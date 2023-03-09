#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "atcoder.h"

// References:
// * https://www.youtube.com/watch?v=niACBP9pHZU
// * https://kyopro-friends.hatenablog.com/entry/2019/01/12/231106
void Main() {
  ints(n, m);

  map<int, V<pair<int, int>>> s;
  rep(m) {
    ints(l, r, a);
    s[r].eb(l, a);
  }

  add_max::segtree tree(n + 1);
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
