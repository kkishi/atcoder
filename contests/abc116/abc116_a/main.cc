#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  vector<int> v(3);
  rep(i, 3) cin >> v[i];
  sort(all(v));
  wt(v[0] * v[1] / 2);
}
