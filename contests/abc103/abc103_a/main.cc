#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  V<int> a(3);
  cin >> a;
  sort(all(a));
  wt(a[2] - a[0]);
}
