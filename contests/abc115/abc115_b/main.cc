#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> p(n);
  cin >> p;
  wt(accumulate(all(p), 0) - *max_element(all(p)) / 2);
}
