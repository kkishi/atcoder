#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

bool ac[100000];
int wa[100000];

int main() {
  ints(N, M);
  rep(i, M) {
    ints(p);
    strings(S);
    if (S == "AC") ac[p - 1] = true;
    if (S == "WA" && !ac[p - 1]) ++wa[p - 1];
  }
  int acs = 0, was = 0;
  rep(i, N) if (ac[i]) {
    ++acs;
    was += wa[i];
  }
  wt(acs, was);
}
