#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  vector<int> d(n);
  cin >> d;
  int sum = 0;
  rep(i, n - 1) rep(j, i + 1, n) sum += d[i] * d[j];
  wt(sum);
}
