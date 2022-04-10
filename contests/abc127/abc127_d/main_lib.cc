#include <bits/stdc++.h>

#include "atcoder.h"
#include "run_length_set.h"

void Main() {
  ints(n, m);
  RunLengthSet st;
  rep(n) {
    ints(a);
    st.Insert(a, 1);
  }
  rep(m) {
    ints(b, c);
    while (b > 0 && st.begin()->first < c) {
      auto [val, cnt] = *st.begin();
      st.Erase(st.begin());
      int del = min(b, cnt);
      b -= del;
      cnt -= del;
      if (cnt > 0) st.Insert(val, cnt);
      st.Insert(c, del);
    }
  }
  wt(st.Sum());
}
