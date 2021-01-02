#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;

  map<int, int> ac, bc, tot;
  rep(i, n) {
    ac[a[i]]++;
    bc[b[i]]++;
    tot[a[i]]++;
    tot[b[i]]++;
  }

  for (auto [_, v] : tot) {
    if (v > n) {
      wt("No");
      return;
    }
  }

  multiset<pair<int, int>, greater<>> rac, rbc, rem;
  for (auto [x, c] : ac) rac.insert({c, x});
  for (auto [x, c] : bc) {
    if (ac.count(x)) {
      rbc.insert({c, x});
    } else {
      rem.insert({c, x});
    }
  }

  V<pair<int, int>> ans;
  for (auto ait = rac.begin(); ait != rac.end(); ++ait) {
    // x is the most frequent element in A.
    auto [c, x] = *ait;
    rep(ci, c) {
      // it points to the most frequent element in B, excluding x.
      auto it = rbc.begin();
      while (it != rbc.end() && it->second == x) {
        auto jt = it;
        ++it;
        rem.insert(*jt);
        rbc.erase(jt);
      }
      if (it == rbc.end()) {
        // Fill ra and rb with the remaining elements from A and B,
        // respectively.
        V<int> ra;
        rep(c - ci) ra.pb(x);
        for (++ait; ait != rac.end(); ++ait) {
          rep(ait->first) ra.pb(ait->second);
        }
        V<int> rb;
        for (auto [c, x] : rem) rep(c) rb.pb(x);
        assert(sz(ra) == sz(rb));

        // Elements from ra and rb are different, except for the remaining x
        // (from the last loop). So rotate rb so that there's no collision.
        if (c > ci) {
          int j = -1;
          rep(i, sz(rb)) if (rb[i] == x) {
            j = i;
            break;
          }
          int rot = (c - ci) - j;
          int m = sz(rb);
          V<int> rc(m);
          rep(i, m) rc[(i + rot + m) % m] = rb[i];
          swap(rc, rb);
        }

        rep(i, sz(ra)) ans.pb({ra[i], rb[i]});
        goto out;
      }
      // Pair x and y, then continue.
      auto [d, y] = *it;
      rbc.erase(it);
      ans.pb({x, y});
      if (d > 1) rbc.insert({d - 1, y});
    }
  }

out:
  rep(i, n) assert(ans[i].first != ans[i].second);

  wt("Yes");
  sort(all(ans));
  rep(i, n) {
    if (i) cout << " ";
    cout << ans[i].second;
  }
  cout << endl;
}
