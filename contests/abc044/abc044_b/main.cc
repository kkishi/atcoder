#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(w);
  map<int, int> m;
  for (char c : w) ++m[c];
  bool ok = true;
  for (auto [_, v] : m)
    if (v & 1) ok = false;
  wt(ok);
}
