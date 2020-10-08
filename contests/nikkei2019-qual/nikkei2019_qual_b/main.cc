#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(3);
  cin >> s;
  int ans = 0;
  rep(i, n) {
    set<char> st;
    rep(j, 3) st.insert(s[j][i]);
    ans += st.size() - 1;
  }
  wt(ans);
}
