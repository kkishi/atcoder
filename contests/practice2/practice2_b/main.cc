#include <bits/stdc++.h>

#include "bit.h"
#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n, q);
  V<int> a(n);
  cin >> a;
  BIT<int> bit(n);
  rep(i, n) bit.Add(i, a[i]);
  rep(q) {
    ints(a, b, c);
    if (a == 0) {
      bit.Add(b, c);
    } else {
      wt(bit.Sum(c - 1) - bit.Sum(b - 1));
    }
  }
}
