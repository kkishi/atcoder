#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> h(n);
  cin >> h;
  stack<pair<int, int>> st;
  for (int hi : h) {
    int ci = 0;
    while (!st.empty()) {
      auto [hj, cj] = st.top();
      if (hj >= hi) break;
      ++ci;
      st.pop();
    }
    wt(ci + st.size());
    st.push({hi, ci + 1});
  }
}
