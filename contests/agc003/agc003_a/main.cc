#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  set<char> st(all(s));
  wt(!st.count('N') == !st.count('S') && !st.count('W') == !st.count('E'));
}
