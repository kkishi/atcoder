#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(N, C);
  V<tuple<int, int, int>> v1;
  rep(i, N) {
    ints(s, t, c);
    v1.push_back({c, s, t});
  }
  sort(all(v1));
  V<tuple<int, int, int>> v2;
  rep(i, v1.size()) {
    if (i + 1 < v1.size() && get<0>(v1[i]) == get<0>(v1[i + 1]) &&
        get<2>(v1[i]) == get<1>(v1[i + 1])) {
      get<1>(v1[i + 1]) = get<1>(v1[i]);
    } else {
      v2.push_back(v1[i]);
    }
  }
  V<tuple<int, int, int>> v;
  for (auto [c, s, t] : v2) {
    v.push_back({s, 0, c});
    v.push_back({t, 1, c});
  }
  sort(all(v));
  int ans = 0;
  set<int> on;
  for (auto [t, pop, c] : v) {
    if (pop) {
      on.erase(c);
    } else {
      on.insert(c);
    }
    chmax(ans, on.size());
  }
  wt(ans);
}
