#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  set<int> st;
  int excess = 0;
  each(e, a) {
    if (st.count(e)) {
      ++excess;
    } else {
      st.insert(e);
    }
  }
  int ans = 0;
  while (true) {
    if (st.count(ans + 1)) {
      st.erase(ans + 1);
    } else if (excess + sz(st) >= 2) {
      while (excess < 2) {
        ++excess;
        st.erase(prev(st.end()));
      }
      excess -= 2;
    } else {
      break;
    }
    ++ans;
  }
  wt(ans);
}
