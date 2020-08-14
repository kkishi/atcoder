#include <bits/stdc++.h>

#include "macros.h"

struct D {
  int l, r, s;
};

using namespace std;

int main() {
  rd(int, n, m);
  dbg(n, m);
  V<D> ds;
  rep(i, n) {
    rd(int, l, r, s);
    ds.push_back({l, r, s});
  }

  sort(all(ds), [](const D& a, const D& b) { return a.r < b.r; });
  V<int> l(m + 2);
  {
    auto it = ds.begin();
    for (int i = 1; i <= m; ++i) {
      int sum = 0;
      while (it != ds.end() && it->r < i) {
        sum += it->s;
        ++it;
      }
      l[i] = l[i - 1] + sum;
    }
  }

  sort(all(ds), [](const D& a, const D& b) { return a.l < b.l; });
  V<int> r(m + 2);
  {
    auto it = ds.rbegin();
    for (int i = m; i >= 1; --i) {
      int sum = 0;
      while (it != ds.rend() && it->l > i) {
        sum += it->s;
        ++it;
      }
      r[i] = r[i + 1] + sum;
    }
  }

  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    chmax(ans, l[i] + r[i]);
  }
  wt(ans);
}
