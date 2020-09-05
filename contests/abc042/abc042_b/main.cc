#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, l);
  V<string> s(n);
  cin >> s;
  sort(all(s));
  wt(accumulate(all(s), ""s));
}
