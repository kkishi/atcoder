#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  rep(i, n) {
    rep(j, n) cout << s[n - 1 - j][i];
    cout << endl;
  }
}
