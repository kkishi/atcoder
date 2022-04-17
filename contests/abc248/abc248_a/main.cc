#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  set<int> st;
  rep(i, 10) st.insert(i);
  strings(s);
  each(e, s) st.erase(e - '0');
  wt(*st.begin());
}
