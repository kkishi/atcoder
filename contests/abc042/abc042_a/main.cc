#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  V<int> a(3);
  cin >> a;
  sort(all(a));
  wt(a == V<int>{5, 5, 7} ? "YES" : "NO");
}
