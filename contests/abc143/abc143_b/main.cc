#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  int sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      sum += d[i] * d[j];
    }
  }
  wt(sum);
}
