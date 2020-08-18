#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  V<char> s(n);
  cin >> s;
  wt(count(all(s), 'Y') ? "Four" : "Three");
}
