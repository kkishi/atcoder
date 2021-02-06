#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  rep(i, n)-- a[i];
  map<int, int> prev;
  V<int> b(n + 1);  // The result of a subproblem a[i:n].
  b[n] = n;
  rrep(i, n) {
    if (auto it = prev.find(a[i]); it == prev.end()) {
      b[i] = i;
    } else {
      b[i] = b[it->second + 1];
    }
    prev[a[i]] = i;
  }

  int iter = 0;
  int pos = n;
  map<int, int> hist;
  hist[pos] = iter;
  while (iter < k) {
    ++iter;
    pos = b[pos == n ? 0 : (prev[a[pos]] + 1)];
    if (hist.count(pos)) {
      int rem = k - iter;
      rem %= iter - hist[pos];
      k = iter + rem;
    }
    hist[pos] = iter;
  }

  // Simulate
  map<int, int> cnt;
  V<int> ans;
  rep(i, pos, n) {
    if (cnt[a[i]] > 0) {
      while (true) {
        bool end = ans.back() == a[i];
        --cnt[ans.back()];
        ans.pop_back();
        if (end) break;
      }
    } else {
      ++cnt[a[i]];
      ans.pb(a[i]);
    }
  }
  each(x, ans)++ x;
  wt(ans);
}
