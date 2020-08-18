#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(s);
  set<int> seen;
  for (int i = 1; i <= 1000000; ++i) {
    if (!seen.insert(s).second) {
      wt(i);
      return 0;
    }
    s = (s & 1) ? (s * 3 + 1) : (s / 2);
  }
}
