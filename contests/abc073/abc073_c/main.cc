#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  set<int> s;
  rep(n) {
    ints(a);
    if (!s.insert(a).second) s.erase(a);
  }
  wt(s.size());
}
