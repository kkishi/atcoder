#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  rep(i, 2) rep(j, 2) {
    V<int> ans{i, j};
    rep(k, 2, n) ans.pb(ans[k - 2] ^ (s[k - 1] == 'x') ^ ans[k - 1]);
    if ((ans[n - 2] ^ (s[n - 1] == 'x') ^ ans[n - 1]) == ans[0] &&
        (ans[1] ^ (s[0] == 'x') ^ ans[0]) == ans[n - 1]) {
      rep(k, n) cout << "SW"[ans[k]];
      cout << endl;
      return;
    }
  }
  wt(-1);
}
