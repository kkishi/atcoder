#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(n);
  int ans = 0;
  const int N = sz(s);
  auto f = [&](int i) { return 1LL << (N - 1 - i); };
  rep(i, N) {
    if (s[i] != '?') {
      if (s[i] == '1') ans += f(i);
    } else {
      int x = ans + f(i);
      rep(j, i + 1, N) if (s[j] == '1') x += f(j);
      if (x <= n) ans += f(i);
    }
  }
  if (ans > n) ans = -1;
  wt(ans);
}
