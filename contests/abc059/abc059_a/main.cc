#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  V<string> s(3);
  cin >> s;
  string ans;
  for (string si : s) ans += toupper(si[0]);
  wt(ans);
}
