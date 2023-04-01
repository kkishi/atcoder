#include <bits/stdc++.h>

#include <atcoder/modint>

#include "atcoder.h"
#include "bsgs.h"
#include "matrix.h"

using mint = atcoder::modint;
using vec = Matrix<mint, 2, 1>;
struct S {
  vec v;
  int cnt;
  bool operator==(const S& s) const { return v == s.v && cnt == s.cnt; }
};

namespace std {
template <>
struct hash<S> {
  inline size_t operator()(const S& s) const {
    return std::hash<int>()((s.v[0][0].val() << 2) | s.cnt);
  }
};
}  // namespace std

namespace std {
ostream& operator<<(ostream& os, mint m) {
  os << m.val();
  return os;
}
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
    mat cba = Mult(v[2], Mult(v[1], v[0]));

    using X = int;
    auto xx = [&](X l, X r) { return l + r; };

    auto xs = [&](X x, S s) {
      while (x) {
        if (x >= 3 && s.cnt == 0) {
          s.v = Mult(Pow(cba, x / 3), s.v);
          x %= 3;
        } else {
          --x;
          s.v = Mult(v[s.cnt], s.v);
          s.cnt = (s.cnt + 1) % 3;
        }
      }
      return s;
    };
    S ss = {vec{{{s}, {1}}}, 0};

    int ans = big;
    rep(i, 3) {
      S tt = {vec{{{t}, {1}}}, i};
      int n = BSGS<X, S>(1, ss, tt, p * 3, xx, xs);
      if (n != -1) chmin(ans, n);
    }
    if (ans == big) ans = -1;
    wt(ans);
  }
}
