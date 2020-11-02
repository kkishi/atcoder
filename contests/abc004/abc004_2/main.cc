#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  VV<char> c(4, V<char>(4));
  cin >> c;
  rep(i, 4) {
    rep(j, 4) {
      if (j) cout << " ";
      cout << c[3 - i][3 - j];
    }
    cout << endl;
  }
}
