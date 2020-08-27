#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, k);
  V<int> l(n);
  cin >> l;
  sort(all(l));
  wt(accumulate(l.rbegin(), l.rbegin() + k, 0));
}
