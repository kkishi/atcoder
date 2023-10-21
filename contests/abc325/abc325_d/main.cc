#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  using P = pair<int, int>;
  V<P> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  sort(v);

  int idx = 0;
  int t = 0;
  multiset<int> in;
  int ans = 0;
  while (true) {
    if (idx == n && in.empty()) break;
    if (in.empty()) {
      t = v[idx].first;
    }
    while (idx < n && v[idx].first == t) {
      in.insert(t + v[idx].second);
      ++idx;
    }
    if (!in.empty()) {
      assert(t <= *in.begin());
      ++ans;
      in.erase(in.begin());
    }
    while (!in.empty() && *in.begin() == t) {
      in.erase(in.begin());
    }
    ++t;
  }
  wt(ans);
}
