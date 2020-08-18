#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  V<int> l(n);
  cin >> l;
  sort(all(l));

  int ans = 0;
  rep(a, n - 2) {
    rep(b, a + 1, n - 1) {
      auto begin = l.begin() + b + 1;
      ans += upper_bound(begin, l.end(), l[a] + l[b] - 1) - begin;
    }
  }
  wt(ans);
}
