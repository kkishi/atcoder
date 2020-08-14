#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<ll> a(n);
  cin >> a;
  map<ll, ll> m;
  rep(i, n) m[a[i]]++;
  rd(int, q);
  ll sum = accumulate(all(a), 0LL);
  while (q--) {
    rd(ll, b, c);
    auto it = m.find(b);
    if (it == m.end()) {
      wt(sum);
      continue;
    }
    ll diff = (c - it->first) * it->second;
    sum += diff;
    wt(sum);
    m[c] += it->second;
    m.erase(it);
  }
  /*
  ll ans = 0;
  for (auto [k, v] : m) {
    ans += k * v;
  }
  wt(ans);
  */
}
