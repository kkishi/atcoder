#include <bits/stdc++.h>

#include "binary_search.h"
#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n, a, b);
  V<int> h(n);
  cin >> h;
  wt(BinarySearch<int>(10000000000LL, 0, [&](int x) {
    V<int> v = h;
    int y = 0;
    rep(i, n) {
      v[i] -= b * x;
      if (v[i] > 0) y += (v[i] + (a - b) - 1) / (a - b);
    }
    return y <= x;
  }));
}
