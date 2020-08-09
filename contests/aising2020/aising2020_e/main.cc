#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct Camel {
  ll k, x;
  bool operator<(const Camel& c) const { return x < c.x; }
};

void solve() {
  rd(int, n);
  ll ans = 0;
  vector<Camel> lc, rc;
  rep(i, n) {
    rd(ll, k, l, r);
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

int main() {
  rd(int, t);
  while (t--) solve();
}
