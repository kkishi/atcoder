#include <bits/stdc++.h>

#include "atcoder.h"
#include "pow.h"
#include "segment_tree.h"

void Main() {
  ints(n, q);
  strings(s);

  using u64 = uint64_t;
  static const u64 mod = (1ULL << 61) - 1;
  u64 base;
  {
    std::random_device d;
    std::mt19937 g(d());
    const u64 r = 37;
    while (true) {
      u64 k = std::uniform_int_distribution<u64>(1, mod - 2)(g);
      if (std::gcd(k, mod - 1) == 1) {
        base = Pow(r, k, mod);
        break;
      }
    }
  }
  auto mul = [](u64 x, u64 y) { return (__uint128_t(x) * y) % mod; };
  auto add = [](u64 x, u64 y) { return (__uint128_t(x) + y) % mod; };
  using hash = pair<u64, int>;
  V<u64> pow(n + 1);
  pow[0] = 1;
  rep(i, n) pow[i + 1] = mul(pow[i], base);
  auto f = [&](hash a, hash b) {
    auto [af, al] = a;
    auto [bf, bl] = b;
    return hash(add(mul(af, pow[bl]), bf), al + bl);
  };
  SegmentTree<hash> t(n, f), u(n, f);
  rep(i, n) {
    t.Set(i, hash(s[i], 1));
    u.Set(i, hash(s[n - 1 - i], 1));
  }
  rep(q) {
    ints(kind);
    if (kind == 1) {
      ints(x);
      rd(char, c);
      --x;
      t.Set(x, hash(c, 1));
      u.Set(n - 1 - x, hash(c, 1));
    } else {
      ints(l, r);
      wt(t.Aggregate(l - 1, r) == u.Aggregate(n - r, n - l + 1));
    }
  }
}
