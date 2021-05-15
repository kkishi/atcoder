#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int ans = 0;
  rep(i, 10000) {
    int I = i;
    set<int> st;
    bool ok = true;
    rep(4) {
      int x = I % 10;
      I /= 10;
      if (s[x] == 'x') ok = false;
      st.insert(x);
    }
    rep(j, 10) if (s[j] == 'o' && !st.count(j)) ok = false;
    if (ok) ++ans;
  }
  wt(ans);
}
