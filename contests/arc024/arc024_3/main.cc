#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  strings(s);
  map<V<int>, int> m;
  V<int> cnt(26);
  rep(i, k - 1) { ++cnt[s[i] - 'a']; }
  rep(i, k - 1, n) {
    ++cnt[s[i] - 'a'];
    auto [it, ok] = m.insert({cnt, i});
    if (!ok && i - it->second >= k) {
      wt("YES");
      return;
    }
    --cnt[s[i - (k - 1)] - 'a'];
  }
  wt("NO");
}
