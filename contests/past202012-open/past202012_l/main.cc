#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s, t);
  map<pair<int, int>, int> dp;
  wt(Fix([&](auto rec, int begin, int end) -> int {
    if (end - begin < 3) return 0;
    if (dp.count({begin, end})) return dp[{begin, end}];
    int ret = 0;
    chmax(ret, rec(begin + 1, end));
    chmax(ret, rec(begin, end - 1));
    for (int mid = begin + 3; mid <= end - 3; ++mid) {
      chmax(ret, rec(begin, mid) + rec(mid, end));
    }
    if (s[begin] == t[0] && s[end - 1] == t[2]) {
      rep(mid, begin + 1, end - 1) if (s[mid] == t[1]) {
        int a = rec(begin + 1, mid);
        int b = rec(mid + 1, end - 1);
        if (a * 3 == (mid - (begin + 1)) && b * 3 == (end - 1 - (mid + 1))) {
          chmax(ret, a + b + 1);
        }
      }
    }
    dp[{begin, end}] = ret;
    return ret;
  })(0, sz(s)));
}
