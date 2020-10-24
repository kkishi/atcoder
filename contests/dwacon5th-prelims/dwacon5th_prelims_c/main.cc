#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  ints(q);
  rep(q) {
    ints(k);
    int ans = 0;
    queue<int> dque;
    queue<int> mque;
    int dm = 0;
    rep(i, n) {
      if (!dque.empty() && i - dque.front() == k) {
        dque.pop();
        dm -= sz(mque);
      }
      if (!mque.empty() && i - mque.front() == k) {
        mque.pop();
      }
      if (s[i] == 'D') {
        dque.push(i);
      } else if (s[i] == 'M') {
        dm += sz(dque);
        mque.push(i);
      } else if (s[i] == 'C') {
        ans += dm;
      }
    }
    wt(ans);
  }
}
