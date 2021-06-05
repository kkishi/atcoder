#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  set<string> st;
  rep(i, n) {
    strings(s);
    if (st.insert(s).second) wt(i + 1);
  }
}
