#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, X, Y);
  vector<int> x(n), y(m);
  cin >> x >> y;
  if (max(X, max(x)) < min(Y, min(y))) {
    wt("No War");
  } else {
    wt("War");
  }
}
