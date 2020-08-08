#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  map<string, int> m;
  rep(i, n) {
    rd(string, s);
    m[s]++;
  }
  for (auto k : {"AC", "WA", "TLE", "RE"}) {
    wt(k, 'x', m[k]);
  }
}
