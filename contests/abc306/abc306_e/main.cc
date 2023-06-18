#include <bits/stdc++.h>

#include "atcoder.h"
#include "twosets.h"

void Main() {
  ints(n, k, q);
  V<int> a(n);
  TwoSets st;
  rep(n) st.Add(0);
  rep(q) {
    ints(x, y);
    --x;
    st.Rem(a[x]);
    a[x] = y;
    st.Add(a[x]);
    st.Adjust(n - k);
    wt(st.HSum());
  }
}
