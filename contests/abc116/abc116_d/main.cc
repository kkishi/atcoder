#include <bits/stdc++.h>

#include "atcoder.h"

struct S {
  int t, d, i;
};

void Main() {
  ints(n, k);
  vector<S> s(n);
  rep(i, n) {
    cin >> s[i].t >> s[i].d;
    s[i].i = i;
  }
  sort(all(s), [](const S& a, const S& b) { return a.d > b.d; });
  set<int> tset;
  int dsum = 0;
  multiset<int> dup;
  rep(i, k) {
    dsum += s[i].d;
    if (!tset.insert(s[i].t).second) {
      dup.insert(s[i].d);
    }
  }
  auto square = [](int x) { return x * x; };
  auto score = [&]() { return dsum + square(tset.size()); };
  int ans = score();
  rep(i, k, n) {
    if (tset.insert(s[i].t).second && !dup.empty()) {
      dsum -= *dup.begin();
      dup.erase(dup.begin());
      dsum += s[i].d;
      chmax(ans, score());
    }
  }
  wt(ans);
}
