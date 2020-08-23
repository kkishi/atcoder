#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(s);
  bool ok = false;
  rep(i, 4) rep(j, i, 4) {
    if (s[j] != s[i]) break;
    if (j - i == 2) ok = true;
  }
  wt(ok);
}
