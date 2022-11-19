#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  vector memo(1 << n, vector(n, false));
  vector seen(1 << n, vector(n, false));
  auto win = Fix([&](auto win, int state, int last) -> bool {
    if (seen[state][last]) return memo[state][last];
    seen[state][last] = true;
    bool res = false;
    rep(i, n) if (!hasbit(state, i) && (!state || s[last].back() == s[i][0])) {
      if (!win((state | (1 << i)), i)) res = true;
    }
    memo[state][last] = res;
    return res;
  });
  wt(win(0, 0) ? "First" : "Second");
}
