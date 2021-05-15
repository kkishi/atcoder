#include <bits/stdc++.h>

#include "atcoder.h"
#include "bidirected_graph.h"
#include "modint.h"
#include "rerooting.h"

using mint = ModInt<>;

using A = array<mint, 60>;

struct S {
  A zero = {}, one = {};
};

S Combine(S a, S b) {
  S c;
  rep(i, 60) {
    c.zero[i] = a.zero[i] + b.zero[i];
    c.one[i] = a.one[i] + b.one[i];
  }
  return c;
}

void Main() {
  ints(n);
  BidirectedGraph<int> g(n);
  rep(n - 1) {
    ints(u, v, w);
    g.AddEdge(u - 1, v - 1, w);
  }
  mint ans = 0;
  V<S> res = Rerooting<S, int>(g, Combine, [](const auto& e, S x) -> S {
    rep(i, 60) {
      x.zero[i] += 1;
      if (hasbit(e.weight, i)) {
        swap(x.zero[i], x.one[i]);
      }
    }
    return x;
  });
  rep(i, 60) {
    mint sum = 0;
    each(r, res) sum += r.one[i];
    sum *= mint(2).Pow(i);
    ans += sum;
  }
  wt(ans / 2);
}
