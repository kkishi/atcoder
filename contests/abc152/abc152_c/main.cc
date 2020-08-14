#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, N);
  int m = numeric_limits<int>::max();
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    rd(int, p);
    chmin(m, p);
    if (m >= p) ++ans;
  }
  wt(ans);
}
