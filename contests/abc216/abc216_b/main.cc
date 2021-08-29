#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  set<string> st;
  bool ans = false;
  rep(n) {
    strings(s, t);
    if (!st.insert(s + '.' + t).second) {
      ans = true;
    }
  }
  wt(ans);
}
