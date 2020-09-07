#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n, t);
  V<int> a(n);
  cin >> a;
  a.push_back(0);

  int mini = a[0];
  int maxi = 0;
  rep(i, 1, sz(a)) {
    chmax(maxi, a[i] - mini);
    chmin(mini, a[i]);
  }

  map<int, int> m{{a[0], 1}};
  int ans = 0;
  rep(i, 1, sz(a)) {
    auto it = m.begin();
    if (a[i] < it->first) {
      auto jt = prev(m.end());
      if (jt->first - it->first == maxi) {
        ans += min(it->second, jt->second);
      }
      m.clear();
    }
    ++m[a[i]];
  }
  wt(ans);
}
