#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  VV<int> to(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    to[a].pb(b);
    to[b].pb(a);
  }

  // Sizes of the subtrees.
  VV<int> sizes(n);
  Fix([&](auto rec, int i, int p) -> int {
    int size = 1;
    each(c, to[i]) {
      if (c == p) continue;
      int cs = rec(c, i);
      size += cs;
      sizes[i].pb(cs);
    }
    if (p != -1) {
      sizes[i].pb(n - size);
    }
    return size;
  })(0, -1);

  mint w = 0;
  V<mint> two(n);
  two[0] = 1;
  rep(i, 1, n) two[i] = two[i - 1] * 2;
  rep(i, n) {
    // Count all combinations where node i is white and is part of a tree.
    mint all = 1;  // All combinations.
    mint one = 0;  // Only one subtree contains a black node.
    each(c, sizes[i]) {
      all *= two[c];
      one += two[c] - 1;
    }
    mint zero = 1;  // No subtree contains a black node.
    w += all - one - zero;
  }
  wt(w / mint(2).Pow(n));
}
