#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  for (int x = 1; x <= n; ++x) {
    if (x * 108 / 100 == n) {
      wt(x);
      return 0;
    }
  }
  wt(":(");
}
