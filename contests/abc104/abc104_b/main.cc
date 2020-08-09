#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

bool ok(const string& s) {
  if (s[0] != 'A') {
    return false;
  }
  if (count(s.begin() + 2, s.end() - 1, 'C') != 1) {
    return false;
  }
  int lower = 0;
  for (char c : s)
    if (islower(c)) ++lower;
  return lower == s.size() - 2;
}

int main() {
  rd(string, s);
  wt(ok(s) ? "AC" : "WA");
}
