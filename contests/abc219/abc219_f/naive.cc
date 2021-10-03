#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(k);
  using P = pair<int, int>;
  P p;
  set<P> st;
  st.insert(p);
  rep(k) {
    each(e, s) {
      if (e == 'L') --p.first;
      if (e == 'R') ++p.first;
      if (e == 'U') --p.second;
      if (e == 'D') ++p.second;
      st.emplace(p);
    }
  }
  wt(sz(st));
}
