#include <bits/stdc++.h>

#include "atcoder.h"
#include "rolling_hash.h"

RollingHash hashes[5000];

void Main() {
  ints(n);
  strings(s);
  rep(i, n) hashes[i].PushBack(s[i]);
  int ans = 0;
  for (int length = 2; length <= n / 2; ++length) {
    unordered_set<RollingHash> seen;
    for (int i = 0; i + length - 1 < n; ++i) {
      hashes[i].PushBack(s[i + length - 1]);
      if (ans == length) continue;
      if (i - length >= 0) {
        seen.insert(hashes[i - length]);
      }
      if (seen.count(hashes[i])) {
        ans = length;
      }
    }
  }
  wt(ans);
}
