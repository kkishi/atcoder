#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(q);
  V<string> st;
  rep(q) {
    strings(s);
    if (s == "READ") {
      wt(st.back());
      st.pop_back();
    } else {
      st.eb(s);
    }
  }
}
