#include <bits/stdc++.h>

#include "atcoder.h"

struct S {
  int idx;
  int cnt;
};

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, S> m;
  rep(i, n) {
    auto it = m.find(a[i]);
    if (it == m.end()) {
      m[a[i]] = {i, 1};
    } else {
      ++it->second.cnt;
    }
  }
  V<int> ans(n);
  while (true) {
    auto it = prev(m.end());
    if (it == m.begin()) {
      ans[it->second.idx] += it->first * it->second.cnt;
      break;
    }
    auto jt = prev(it);
    ans[it->second.idx] += (it->first - jt->first) * it->second.cnt;
    jt->second.cnt += it->second.cnt;
    chmin(jt->second.idx, it->second.idx);
    m.erase(it);
  }
  rep(i, n) wt(ans[i]);
}
