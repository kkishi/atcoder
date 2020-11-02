#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  strings(s);
  vector<pair<bool, int>> v;
  int l = -1;
  dbg(s);
  rep(i, n) if (i + 1 == n || s[i] != s[i + 1]) {
    bool zero = s[i] == '0';
    v.push_back({zero, i - l});
    l = i;
    // dbg(v.back());
  }
  queue<pair<bool, int>> q;
  int sum = 0;
  int ans = 0;
  for (auto [zero, cnt] : v) {
    sum += cnt;
    if (zero) --k;
    q.push({zero, cnt});
    while (k < 0) {
      auto [z, c] = q.front();
      q.pop();
      sum -= c;
      if (z) ++k;
    }
    chmax(ans, sum);
  }
  wt(ans);
}
