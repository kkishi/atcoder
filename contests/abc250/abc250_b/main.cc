#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b);
  rep(i, a * n) {
    rep(j, b * n) {
      int x = even(i / a) ^ even(j / b);
      if (x == 0) {
        cout << ".";
      } else {
        cout << "#";
      }
    }
    cout << endl;
  }
}
