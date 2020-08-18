#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  vector<int> l(n);
  cin >> l;
  int s = accumulate(all(l), 0);
  bool ok = true;
  rep(i, n) if (s - l[i] <= l[i]) ok = false;
  wt(ok);
}
