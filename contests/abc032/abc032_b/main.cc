#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(k);
  set<string> st;
  rep(i, sz(s)) if (i + k <= sz(s)) st.insert(s.substr(i, k));
  wt(sz(st));
}
