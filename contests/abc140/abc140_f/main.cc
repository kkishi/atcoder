#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  multiset<int, greater<int>> ms;
  rep(i, 1 << n) {
    ints(s);
    ms.insert(s);
  }
  vector<int> v;
  v.pb(*ms.begin());
  ms.erase(ms.begin());
  rep(i, n) {
    int J = v.size();
    rep(j, J) {
      const auto it = ms.lower_bound(v[j] - 1);
      if (it == ms.end()) {
        wt("No");
        return;
      }
      v.pb(*it);
      ms.erase(it);
    }
  }
  wt("Yes");
}
