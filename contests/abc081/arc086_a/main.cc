#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  rep(i, n)++ m[a[i]];
  multiset<int> ms;
  for (auto [_, v] : m) ms.insert(v);
  int ans = 0;
  while (ms.size() > k) {
    auto it = ms.begin();
    ans += *it;
    ms.erase(it);
  }
  wt(ans);
}
