#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct Pair {
  ll l, r;
  ll Min() const { return min(l, r); }
  bool operator<(const Pair& p) const { return Min() < p.Min(); }
};

int main() {
  rd(ll, n);
  vector<ll> a(n);
  cin >> a;
  sort(all(a), greater());

  ll ans = a[0];
  priority_queue<Pair> que;
  que.push({a[0], a[1]});
  que.push({a[1], a[0]});
  for (int i = 2; i < n; ++i) {
    Pair p = que.top();
    dbg(i, ans, p.l, p.r, p.Min());
    que.pop();
    ans += p.Min();
    que.push({p.l, a[i]});
    que.push({a[i], p.r});
  }
  wt(ans);
}
