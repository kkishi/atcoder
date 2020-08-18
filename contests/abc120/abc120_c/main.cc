#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(s);
  vector<int> v(2);
  rep(i, s.size())++ v[s[i] - '0'];
  wt(min(v[0], v[1]) * 2);
}
