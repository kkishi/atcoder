#include <bits/stdc++.h>

#include "binary_search.h"
#include "macros.h"

using namespace std;

int main() {
#define int ll
  rd(int, q);
  while (q--) {
    rd(int, a, b);
    if (a * b <= 2) {
      wt(0);
      continue;
    }
    wt(BinarySearch<int>(1, 10000000000LL, [&](int x) {
      if (x & 1) {
        int m1 = (x + 1) / 2;
        if (a <= m1) ++m1;
        int m2 = (x + 1) / 2;
        if (b <= m2) ++m2;
        return m1 * m2 < a * b;
      }
      int l1 = x / 2, r1 = x / 2 + 1;
      if (a <= l1)
        ++l1, ++r1;
      else if (a <= r1)
        ++r1;
      int l2 = x / 2, r2 = x / 2 + 1;
      if (b <= l2)
        ++l2, ++r2;
      else if (b <= r2)
        ++r2;
      return max(l1 * r2, r1 * l2) < a * b;
    }));
  }
#undef int
}
