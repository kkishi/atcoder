#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(n), c(m), d(m);
  cin >> a >> b >> c >> d;
  map<int, V<pair<int, bool>>> mp;
  rep(i, n) mp[a[i]].eb(b[i], false);
  rep(i, m) mp[c[i]].eb(d[i], true);
  multiset<int> st;
  each(_, v, mp) {
    sort(v);
    each(y, box, v) {
      if (!box) {
        st.insert(y);
      } else {
        auto it = st.lower_bound(y + 1);
        if (it != st.begin()) {
          st.erase(prev(it));
        }
      }
    }
  }
  wt(st.empty());
}
