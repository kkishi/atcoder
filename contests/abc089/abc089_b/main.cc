#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  V<char> s(n);
  cin >> s;
  wt(count(all(s), 'Y') ? "Four" : "Three");
}
