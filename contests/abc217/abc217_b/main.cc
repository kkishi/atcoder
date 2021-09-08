#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  set<string> st = {"ABC", "ARC", "AGC", "AHC"};
  V<string> v(3);
  cin >> v;
  each(e, v) st.erase(e);
  wt(*st.begin());
}
