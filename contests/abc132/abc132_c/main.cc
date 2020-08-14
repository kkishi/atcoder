#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> d(n);
  cin >> d;
  sort(all(d));
  wt(d[n / 2] - d[n / 2 - 1]);
}
