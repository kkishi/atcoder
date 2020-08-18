#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  strings(s);
  rep(i, s.size()) s[i] = (s[i] - 'A' + n) % 26 + 'A';
  wt(s);
}
