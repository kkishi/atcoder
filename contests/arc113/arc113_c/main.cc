#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int ans = 0;
  V<int> cnt(26);
  rrep(i, sz(s)) {
    int c = s[i] - 'a';
    if (i > 0 && s[i - 1] == s[i]) {
      rep(j, 26) if (j != c) {
        ans += cnt[j];
        cnt[c] += cnt[j];
        cnt[j] = 0;
      }
    }
    ++cnt[c];
  }
  wt(ans);
}
