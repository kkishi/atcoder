#include <bits/stdc++.h>

#include "factorize.h"
#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, k);
  vector<ll> a(n);
  cin >> a;
  ll sum = accumulate(all(a), 0LL);
  map<ll, int> fs = Factorize(sum);
  vector<pair<ll, int>> v(all(fs));

  auto check = [&](ll g) {
    vector<ll> mods(n);
    rep(i, n) mods[i] = a[i] % g;
    sort(all(mods));
    vector<ll> upper(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      upper[i] = upper[i + 1] + g - mods[i];
    }
    vector<ll> lower(n + 1);
    rep(i, n) { lower[i + 1] = lower[i] + mods[i]; }
    rep(i, n) {
      ll l = lower[i + 1], u = upper[i + 1];
      dbg(g, l, u);
      if (l > k) continue;
      if (l == u) {
        return true;
      }
    }
    return false;
  };

  wt(Fix([&](auto dfs, int depth, ll g) -> ll {
    if (depth == v.size()) {
      if (check(g)) {
        return g;
      }
      return 0LL;
    }
    ll ret = 0;
    rep(i, v[depth].second + 1) {
      chmax(ret, dfs(depth + 1, g));
      g *= v[depth].first;
    }
    return ret;
  })(0, 1));
}
