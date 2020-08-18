#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, q);
  strings(s);
  vector<int> cum(n);
  for (int i = 1; i < s.size(); ++i) {
    cum[i] = cum[i - 1];
    if (s[i - 1] == 'A' && s[i] == 'C') ++cum[i];
  }
  while (q--) {
    ints(l, r);
    wt(cum[r - 1] - cum[l - 1]);
  }
}
