#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> cnt(n);
  set<pair<int, int>> st;
  rep(m) {
    ints(a);
    --a;
    st.erase(pair{cnt[a], -a});
    ++cnt[a];
    st.insert(pair{cnt[a], -a});
    wt(-prev(st.end())->second + 1);
  }
}
