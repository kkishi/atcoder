#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  V<map<string, int>> l(n + 1), r(n + 1);
  rep(bits, 1 << n) {
    auto bit = [&](int i) { return (bits >> i) & 1; };
    {
      string t;
      rep(i, n) if (bit(i)) t += s[i];
      rrep(i, n) if (!bit(i)) t += s[i];
      ++l[popcount(bits)][t];
    }
    {
      string t;
      rrep(i, n) if (!bit(i)) t += s[n + i];
      rep(i, n) if (bit(i)) t += s[n + i];
      ++r[popcount(bits)][t];
    }
  }
  int ans = 0;
  rep(i, n + 1) for (auto [k, v] : l[i]) ans += v * r[n - i][k];
  wt(ans);
}
