#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  rep(i, n + 1) {
    cout << [&]() -> char {
      rep(j, 1, 10) {
        if (n % j) continue;
        if (i % (n / j)) continue;
        return (char)('0' + j);
      }
      return '-';
    }();
  }
  cout << endl;
}
