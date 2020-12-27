#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> mod(m);
  map<int, int> cnt;
  rep(n) {
    ints(x);
    ++mod[x % m];
    ++cnt[x];
  }
  V<int> mod_pair(m);
  for (auto [k, v] : cnt) {
    mod_pair[k % m] += v / 2;
  }
  int ans = mod[0] / 2;
  rep(i, 1, m) {
    int j = m - i;
    if (j < i) break;
    if (j == i) {
      ans += mod[i] / 2;
      break;
    }
    int x = min(mod[i], mod[j]);
    int ip = min((mod[i] - x) / 2, mod_pair[i]);
    int jp = min((mod[j] - x) / 2, mod_pair[j]);
    ans += x + ip + jp;
  }
  wt(ans);
}
