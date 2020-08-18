#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(N);
  int m = numeric_limits<int>::max();
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ints(p);
    chmin(m, p);
    if (m >= p) ++ans;
  }
  wt(ans);
}
