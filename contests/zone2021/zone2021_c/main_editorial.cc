#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n);
  vector v(n, vector(5, int(0)));
  cin >> v;
  wt(BinarySearch<int>(0, big, [&](int x) {
    set<int> st;
    rep(i, n) {
      int mask = 0;
      rep(j, 5) if (v[i][j] >= x) mask |= 1 << j;
      st.insert(mask);
    }
    each(a, st) each(b, st) each(c, st) {
      if ((a | b | c) == ((1 << 5) - 1)) return true;
    }
    return false;
  }));
}
