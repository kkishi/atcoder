#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(x);
  V<int> ord(26);
  rep(i, 26) ord[x[i] - 'a'] = i;
  ints(n);
  V<string> s(n);
  cin >> s;
  V<pair<string, string>> ans;
  rep(i, n) {
    string t = s[i];
    each(e, t) e = 'a' + ord[e - 'a'];
    ans.eb(t, s[i]);
  }
  sort(all(ans));
  each(_, e, ans) wt(e);
}
