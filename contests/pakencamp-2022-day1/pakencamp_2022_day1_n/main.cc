#include <bits/stdc++.h>

#include <atcoder/modint>

#include "atcoder.h"
#include "bsgs.h"
#include "matrix.h"

using mint = atcoder::modint;
using vec = Matrix<mint, 2, 1>;
using S = vec;

namespace std {
template <>
struct hash<S> {
  inline size_t operator()(const S& s) const {
    return std::hash<int>()(s[0][0].val());
  }
};
}  // namespace std

void Main() {
  ints(t);
  rep(t) {
    ints(s, t, p);

    mint::set_mod(p);

    using mat = Matrix<mint, 2, 2>;
    V<mat> v;
    rep(3) {
      ints(a, b);
      mat m = {{{a, b}, {0, 1}}};
      v.eb(m);
    }

    int ans = big;
    rep(i, 3) {
      S ss = {{{s}, 1}};
      rep(j, i) ss = Mult(v[j], ss);
      S tt = {{{t}, 1}};
      using X = mat;
      X x = Identity<mint, 2>();
      rep(j, 3) x = Mult(v[(i + j) % 3], x);
      auto xx = [](X l, X r) { return Mult(l, r); };
      auto xs = [](X x, S s) { return Mult(x, s); };
      int n = BSGS<X, S>(x, ss, tt, p, xx, xs);
      if (n != -1) chmin(ans, n * 3 + i);
    }
    if (ans == big) ans = -1;
    wt(ans);
  }
}
