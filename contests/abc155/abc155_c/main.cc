#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(N);

  map<string, int> m;
  int maximum = 0;
  rep(N) {
    strings(s);
    m[s]++;
    chmax(maximum, m[s]);
  }

  for (const auto& [k, v] : m) {
    if (v == maximum) wt(k);
  }
}
