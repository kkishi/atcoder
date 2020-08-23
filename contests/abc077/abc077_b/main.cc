#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  int ans = 0;
  for (int i = 1; i * i <= n; ++i) chmax(ans, i * i);
  wt(ans);
}
