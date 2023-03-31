#include <bits/stdc++.h>

#include <atcoder/modint>

#include "atcoder.h"
#include "bsgs.h"

using mint = atcoder::modint;

namespace std {
template <>
struct hash<mint> {
  inline size_t operator()(const mint& v) const {
    return std::hash<int>()(v.val());
  }
};
}  // namespace std

void Main() {
  ints(t);
  rep(t) {
    ints(k);
    mint::set_mod(k);
    struct X {
      mint a, b;
    };
    using S = mint;
    X x{10, 2};
    auto xx = [](X l, X r) -> X { return {l.a * r.a, l.a * r.b + l.b}; };
    auto xs = [](X l, S r) -> S { return l.a * r + l.b; };
    int n = BSGS<X, S>(x, 2, 0, k, xx, xs);
    if (n != -1) ++n;
    wt(n);
  }
}
