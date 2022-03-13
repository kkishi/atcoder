#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(int, n);
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  vector<vector<pair<int, int>>> counts(2);
  rep(i, 2) {
    map<int, int> m;
    for (int j = i; j < n; j += 2) m[v[j]]++;
    for (auto [k, v] : m) {
      counts[i].pb({v, k});
    }
    sort(counts[i], greater{});
  }
  rep(i, 2) for (auto [k, v] : counts[i]) dbg(i, k, v);
  rep(i, 2) dbg(counts[i].size());
  // 1 2 3 1 1 1
  // 1 3 1
  // 2 1 1
  // 1 2 1 2 1 2
  // 2 1 2 1 2 1

  if (counts[0][0].second != counts[1][0].second) {
    wt(n - (counts[0][0].first + counts[1][0].first));
  } else {
    vector<int> second(2);
    rep(i, 2) second[i] = counts[i].size() == 1 ? 0 : counts[i][1].first;
    rep(i, 2) dbg(second[i]);
    wt(n - max(counts[0][0].first + second[1], counts[1][0].first + second[0]));
  }
}
