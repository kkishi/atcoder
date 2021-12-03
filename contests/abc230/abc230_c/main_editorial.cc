#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b, p, q, r, s);
  rep(i, p, q + 1) {
    rep(j, r, s + 1) {
      cout << ((i - j == a - b || i + j == a + b) ? '#' : '.');
    }
    cout << endl;
  }
}
