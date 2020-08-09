#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  rd(int, a, b);
  wt(max({a + b, a - b, a * b}));
}
