#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n);
  V<pair<int, int>> v(n);
  cin >> v;
  sort(v);
  wt(BinarySearch<int>(0, big, [&](int X) {
    deque<pair<int, int>> que;
    set<int> st;
    each(x, y, v) {
      while (!que.empty() && x - que.front().first >= X) {
        st.insert(que.front().second);
        que.pop_front();
      }
      if (!st.empty()) {
        if (y - *st.begin() >= X || *prev(st.end()) - y >= X) return true;
      }
      que.push_back({x, y});
    }
    return false;
  }));
}
