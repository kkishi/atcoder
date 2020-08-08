#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  int v[5];
  rep(i, 5) cin >> v[i];
  wt(15 - accumulate(v, v + 5, 0));
}
