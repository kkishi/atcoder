#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  ints(n);
  set<string> st = {"and", "not", "that", "the", "you"};
  rep(n) {
    strings(s);
    if (st.count(s)) return true;
  }
  return false;
}
