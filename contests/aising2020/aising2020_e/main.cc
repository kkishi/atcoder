#include <bits/stdc++.h>

#include "atcoder.h"

struct Camel {
  int k, x;
  bool operator<(const Camel& c) const { return x < c.x; }
};

void solve() {
  ints(n);
  int ans = 0;
  vector<Camel> lc, rc;
  rep(i, n) {
    ints(k, l, r);
    if (l >= r) {
      ans += r;
      lc.push_back({k, l - r});
    } else {
      ans += l;
      rc.push_back({k, r - l});
    }
  }
  auto calc = [&ans](const vector<Camel>& cs) {
    multiset<Camel> m;
    for (const auto& c : cs) {
      if (c.k == 0) continue;
      if (m.size() == c.k) {
        auto it = m.begin();
        if (it->x >= c.x) {
          continue;
        }
        ans -= it->x;
        m.erase(it);
      }
      assert(m.size() < c.k);
      ans += c.x;
      m.insert(c);
    }
  };

  auto less = [](const Camel& a, const Camel& b) { return a.k < b.k; };
  sort(all(lc), less);
  calc(lc);

  for (auto& c : rc) {
    c.k = n - c.k;
  }
  sort(all(rc), less);
  calc(rc);

  wt(ans);
}

void Main() {
  ints(t);
  while (t--) solve();
}
