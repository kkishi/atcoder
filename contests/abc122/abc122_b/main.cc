#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

bool acgt(char c) { return string("ACGT").find(c) != string::npos; }

int main() {
  strings(s);
  int ans = 0;
  rep(i, s.size()) for (int j = i; j < s.size(); ++j) {
    bool ok = true;
    for (int k = i; k <= j; ++k)
      if (!acgt(s[k])) ok = false;
    if (ok) chmax(ans, j - i + 1);
  }
  wt(ans);
}
