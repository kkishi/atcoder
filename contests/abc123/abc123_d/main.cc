#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct S {
  ll p;
  int abi, ci;
  bool operator<(const S& s) const { return p < s.p; }
};

int main() {
  rd(ll, x, y, z, k);
  vector<ll> a(x), b(y), c(z);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];
  sort(all(a), greater());
  sort(all(b), greater());
  sort(all(c), greater());
  set<tuple<ll, ll, ll>> seen;
  priority_queue<pair<ll, tuple<ll, ll, ll>>> que;
  auto push = [&](ll ai, ll bi, ll ci) {
    if (ai == a.size() || bi == b.size() || ci == c.size()) {
      return;
    }
    tuple<ll, ll, ll> t = {ai, bi, ci};
    if (seen.count(t)) return;
    seen.insert(t);
    que.push({a[ai] + b[bi] + c[ci], t});
  };
  push(0, 0, 0);
  rep(i, k) {
    auto [s, t] = que.top();
    que.pop();
    wt(s);
    auto [ai, bi, ci] = t;
    push(ai + 1, bi, ci);
    push(ai, bi + 1, ci);
    push(ai, bi, ci + 1);
  }
}
