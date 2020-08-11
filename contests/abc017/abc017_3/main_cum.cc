#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, m);

  int total = 0;
  V<int> inc(m + 1);
  rep(i, n) {
    rd(int, l, r, s);
    total += s;
    inc[l - 1] += s;
    inc[r] -= s;
  }
  int sum = 0;
  int mini = numeric_limits<int>::max();
  rep(i, m) {
    sum += inc[i];
    mini = min(mini, sum);
  }
  wt(total - mini);
}
