#include <bits/stdc++.h>
#include <pbds.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  --k;
  V<int> p(n);
  cin >> p;
  Set<int> st;
  rep(i, n) {
    st.insert(p[i]);
    if (i >= k) {
      wt(*st.find_by_order(i - k));
    }
  }
}
