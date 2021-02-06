#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"

inline int Now() {
  return chrono::duration_cast<chrono::milliseconds>(
             chrono::system_clock::now().time_since_epoch())
      .count();
}

int start;

int Naive(const V<int>& a) {
  set<int> s(all(a));
  for (auto it = prev(s.end()); it != s.begin(); --it) {
    if (Now() - start >= 1000) return -1;
    set<int> ns;
    each(x, s) ns.insert(gcd(x, *it));
    each(x, ns) s.insert(x);
  }
  int ans = 0;
  each(x, s) if (x <= a[0])++ ans;
  return ans;
}

void Main() {
  start = Now();

  ints(n);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  a.erase(unique(all(a)), a.end());

  if (int ans = Naive(a); ans != -1) {
    wt(ans);
    return;
  }

  int ans = 0;
  set<int> seen;
  each(x, a) {
    map<int, int> fs = Factorize(x);
    Fix([&](auto rec, auto it, int p) -> void {
      if (p > a[0]) return;
      if (it == fs.end()) {
        if (!seen.insert(p).second) return;
        int g = 0;
        each(y, a) {
          if (y % p == 0) {
            g = gcd(g, y / p);
            if (g == 1) break;
          }
        }
        if (g == 1) ++ans;
        return;
      }
      auto [k, v] = *it;
      rep(i, v + 1) {
        rec(next(it), p);
        p *= k;
      }
    })(fs.begin(), 1);
  }
  wt(ans);
}
