#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  vector<vector<int>> a(n, vector<int>(n - 1));
  rep(i, n) rep(j, n - 1) cin >> a[i][j];

  set<pair<int, int>> s1;
  set<pair<int, int>> s2;
  vector<int> indice(n);
  auto advance = [&](int x) {
    int y = a[x][indice[x]] - 1;
    ++indice[x];
    if (x > y) swap(x, y);
    const auto it = s1.insert({x, y});
    if (!it.second) {
      s2.insert({x, y});
    }
  };
  rep(i, n) advance(i);
  int ans = 0;
  int completed = 0;
  while (true) {
    vector<pair<int, int>> v(all(s2));
    if (v.empty()) {
      wt(-1);
      return 0;
    }
    for (const auto p : v) {
      advance(p.first);
      advance(p.second);
      s2.erase(p);
      ++completed;
    }
    ++ans;
    if (completed == n * (n - 1) / 2) break;
  }
  wt(ans);
}
