#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, q);
  vector<int> s(a);
  cin >> s;
  set<int> ss(all(s));
  vector<int> t(b);
  cin >> t;
  set<int> ts(all(t));
  while (q--) {
    ints(x);
    auto lohi = [](const set<int>& s, int x) {
      vector<int> v;
      auto it = s.lower_bound(x);
      if (it == s.end()) {
        --it;
        v.push_back(*it);
      } else {
        v.push_back(*it);
        if (it != s.begin()) {
          --it;
          v.push_back(*it);
        }
      }
      return v;
    };
    int ans = big;
    for (int sx : lohi(ss, x)) {
      for (int tx : lohi(ts, x)) {
        chmin(ans, abs(x - sx) + abs(sx - tx));
        chmin(ans, abs(x - tx) + abs(tx - sx));
      }
    }
    wt(ans);
  }
}
