#include <bits/stdc++.h>

#include "pclib/macros.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

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
