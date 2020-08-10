#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, m, X, Y);
  vector<int> x(n), y(m);
  rep(i, n) cin >> x[i];
  rep(i, m) cin >> y[i];
  if (max(X, *max_element(all(x))) < min(Y, *min_element(all(y)))) {
    wt("No War");
  } else {
    wt("War");
  }
}
