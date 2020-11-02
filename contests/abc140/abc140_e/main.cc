#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  int ans = 0;
  rep(2) {
    V<int> l(n);
    {
      stack<pair<int, int>> s;
      s.push({numeric_limits<int>::max(), -1});
      rep(i, n) {
        while (s.top().first < p[i]) {
          s.pop();
        }
        l[i] = i - s.top().second;
        s.push({p[i], i});
      }
    }
    VV<int> rr(n);
    {
      stack<pair<int, int>> s;
      s.push({numeric_limits<int>::max(), n});
      rrep(i, n) {
        while (s.top().first < p[i]) {
          s.pop();
        }
        if (int j = s.top().second; j != n) {
          rr[j].push_back(i);
        }
        s.push({p[i], i});
      }
    }
    V<int> r(n);
    {
      set<pair<int, int>> s;
      s.insert({numeric_limits<int>::max(), n});
      rrep(i, n) {
        for (int j : rr[i]) {
          auto it = s.lower_bound({p[j], 0});
          r[j] = it->second - i;
        }
        while (s.begin()->first < p[i]) s.erase(s.begin());
        s.insert({p[i], i});
      }
    }
    rep(i, n) ans += p[i] * l[i] * r[i];
    reverse(all(p));
  }
  wt(ans);
}
