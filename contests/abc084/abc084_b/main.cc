#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(a, b);
  strings(s);
  bool ok = true;
  rep(i, a) if (!isdigit(s[i])) ok = false;
  if (s[a] != '-') ok = false;
  rep(i, b) if (!isdigit(s[a + 1 + i])) ok = false;
  wt(ok);
}
