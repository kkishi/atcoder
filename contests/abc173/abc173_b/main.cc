#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  map<string, int> m;
  rep(i, n) {
    strings(s);
    m[s]++;
  }
  for (auto k : {"AC", "WA", "TLE", "RE"}) {
    wt(k, 'x', m[k]);
  }
}
