#include <bits/stdc++.h>

#include "atcoder.h"

struct P {
  int x, y;
};

bool operator<(const P& p, const P& q) { return p.y * q.x < q.y * p.x; };

void Main() {
  ints(n);
  using PP = pair<P, P>;
  V<PP> v;
  rep(n) {
    ints(x, y);
    auto normalize = [](P p) {
      if (p.x == 0) return P{0, 1};
      if (p.y == 0) return P{1, 0};
      int g = gcd(p.x, p.y);
      return P{p.x / g, p.y / g};
    };
    v.eb(normalize(P{x, y - 1}), normalize(P{x - 1, y}));
  }
  sort(all(v), [&](const PP& a, const PP& b) { return a.second < b.second; });
  P curr = {1, 0};
  int ans = 0;
  each(e, v) {
    if (!(e.first < curr)) {
      curr = e.second;
      ++ans;
    }
  }
  wt(ans);
}
