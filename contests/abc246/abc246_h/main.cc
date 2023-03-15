#include <bits/stdc++.h>

#include "atcoder.h"
#include "matrix.h"
#include "modint.h"
#include "segment_tree.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, q);
  strings(s);

  using M = Matrix<mint, 4, 4>;
  map<char, M> mp = {
      {
          '0',
          {{
              {1, 1, 0, 0},
              {0, 1, 0, 0},
              {1, 0, 0, 1},
              {0, 0, 0, 1},
          }},
      },
      {
          '1',
          {{
              {1, 0, 1, 0},
              {1, 0, 0, 1},
              {0, 0, 1, 0},
              {0, 0, 0, 1},
          }},
      },
      {
          '?',
          {{
              {2, 0, 0, 1},
              {1, 0, 0, 1},
              {1, 0, 0, 1},
              {0, 0, 0, 1},
          }},
      },
  };

  SegmentTree<M> t(
      n, [](M a, M b) { return Mult(a, b); }, Identity<mint, 4>());
  rep(i, n) t.Set(i, mp[s[i]]);

  rep(q) {
    ints(x);
    rd(char, c);
    t.Set(x - 1, mp[c]);
    using V = Matrix<mint, 1, 4>;
    V ini = {{1, 0, 0, 0}};
    ini = Mult(ini, t.Aggregate(0, n));
    wt(accumulate(ini[0]) - 1);
  }
}
