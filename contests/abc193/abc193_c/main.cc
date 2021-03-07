#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  set<int> st;
  for (int i = 2; i * i <= n; ++i) {
    int j = i * i;
    while (j <= n) {
      st.insert(j);
      j *= i;
    }
  }
  wt(n - sz(st));
}
