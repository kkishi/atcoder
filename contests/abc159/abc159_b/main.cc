#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

bool pal(const string& s) {
  string t = s;
  reverse(all(t));
  return s == t;
}

int main() {
  strings(s);
  string a = s.substr(0, (s.size() - 1) / 2);
  string b = s.substr((s.size() + 3) / 2 - 1);
  wt(pal(s) && pal(a) && pal(b));
}
