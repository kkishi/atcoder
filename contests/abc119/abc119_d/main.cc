#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, a, b, q);
  vector<ll> s(a);
  rep(i, a) cin >> s[i];
  set<ll> ss(all(s));
  vector<ll> t(b);
  rep(i, b) cin >> t[i];
  set<ll> ts(all(t));
  while (q--) {
    rd(ll, x);
    auto lohi = [](const set<ll>& s, ll x) {
      vector<ll> v;
      auto it = s.lower_bound(x);
      if (it == s.end()) {
        --it;
        v.push_back(*it);
      } else {
        v.push_back(*it);
        if (it != s.begin()) {
          --it;
          v.push_back(*it);
        }
      }
      /*
      dbg(x);
      for (ll sx : s) cerr << sx << " ";
      cerr << endl;
      for (ll sx : v) cerr << sx << " ";
      cerr << endl;
      */
      return v;
    };
    ll ans = numeric_limits<ll>::max();
    for (ll sx : lohi(ss, x)) {
      for (ll tx : lohi(ts, x)) {
        ans = min(ans, abs(x - sx) + abs(sx - tx));
        ans = min(ans, abs(x - tx) + abs(tx - sx));
      }
    }
    wt(ans);
  }
}
