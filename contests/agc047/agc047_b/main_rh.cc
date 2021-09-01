#include <bits/stdc++.h>

#include "atcoder.h"
#include "rolling_hash.h"

void Main() {
  ints(n);

  V<string> s(n);
  rep(i, n) {
    cin >> s[i];
    reverse(all(s[i]));
  }
  sort(all(s), [](auto &a, auto &b) { return a.size() > b.size(); });

  int ans = 0;
  unordered_map<RollingHash, array<int, 26>> m;
  for (auto &si : s) {
    vector<bitset<26>> cum(si.size() + 1);
    rrep(i, si.size()) {
      cum[i] = cum[i + 1];
      cum[i].set(si[i] - 'a');
    }
    RollingHash h;
    rep(i, si.size() - 1) {
      rep(j, 26) {
        if (cum[i][j]) {
          m[h][j]++;
        }
      }
      h.Add(si[i]);
    }
    ans += m[h][si.back() - 'a'];
  }
  wt(ans);
}
