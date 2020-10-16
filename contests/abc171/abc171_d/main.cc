#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> a(n);
  cin >> a;
  map<int, int> m;
  rep(i, n) m[a[i]]++;
  ints(q);
  int sum = accumulate(all(a), 0LL);
  while (q--) {
    ints(b, c);
    auto it = m.find(b);
    if (it == m.end()) {
      wt(sum);
      continue;
    }
    int diff = (c - it->first) * it->second;
    sum += diff;
    wt(sum);
    m[c] += it->second;
    m.erase(it);
  }
}
