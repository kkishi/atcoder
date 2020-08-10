#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct S {
  ll t, d, i;
};

int main() {
  rd(ll, n, k);
  vector<S> s(n);
  rep(i, n) {
    cin >> s[i].t >> s[i].d;
    s[i].i = i;
  }
  sort(all(s), [](const S& a, const S& b) { return a.d > b.d; });
  set<ll> tset;
  ll dsum = 0;
  multiset<ll> dup;
  rep(i, k) {
    dsum += s[i].d;
    if (!tset.insert(s[i].t).second) {
      dup.insert(s[i].d);
    }
  }
  auto square = [](ll x) { return x * x; };
  auto score = [&]() { return dsum + square(tset.size()); };
  ll ans = score();
  for (int i = k; i < n; ++i) {
    if (tset.insert(s[i].t).second && !dup.empty()) {
      dsum -= *dup.begin();
      dup.erase(dup.begin());
      dsum += s[i].d;
      ans = max(ans, score());
    }
  }
  wt(ans);
}
