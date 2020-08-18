#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, m);
  vector<vector<pair<int, int>>> v(n);
  rep(i, m) {
    ints(p, y);
    v[p - 1].push_back({y, i});
  }
  for (auto& vi : v) sort(all(vi));
  vector<pair<int, int>> px(m);
  rep(i, n) rep(x, v[i].size()) px[v[i][x].second] = {i, x};
  for (auto [p, x] : px) printf("%06d%06d\n", p + 1, x + 1);
}
