#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  strings(s);
  low_priority_queue<pair<char, int>> que;
  string ans;
  int l = -1;
  rep(i, n) {
    que.emplace(s[i], i);
    if (n - i <= k) {
      while (!que.empty() && que.top().second <= l) que.pop();
      auto [a, b] = que.top();
      que.pop();
      ans += a;
      l = b;
    }
  }
  wt(ans);
}
