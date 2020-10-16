#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  multiset<int> st{0, 0, 0};
  mint ans = 1;
  for (int ai : a) {
    int cnt = st.count(ai);
    if (cnt == 0) {
      wt(0);
      return;
    }
    ans *= cnt;
    st.erase(st.find(ai));
    st.insert(ai + 1);
  }
  wt(ans);
}
