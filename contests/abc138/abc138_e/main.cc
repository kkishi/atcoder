#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  s += s;
  V<int> last(26, -1);
  VV<int> next(s.size(), V<int>(26));
  rrep(i, s.size()) {
    last[s[i] - 'a'] = i;
    rep(j, 26) next[i][j] = last[j] == -1 ? -1 : last[j] - i;
  }
  int ans = 0;
  int si = 0;
  rep(i, t.size()) {
    int n = next[si][t[i] - 'a'];
    if (n == -1) {
      wt(-1);
      return;
    }
    ans += n + 1;
    si = (si + n + 1) % (s.size() / 2);
  }
  wt(ans);
}
