#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  set<int> st = {0};
  rep(n) {
    ints(a, b);
    set<int> nst;
    each(e, st) {
      nst.insert(e + a);
      nst.insert(e + b);
    }
    swap(st, nst);
  }
  wt(st.count(x) > 0);
}
