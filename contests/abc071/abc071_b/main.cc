#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(s);
  set<char> ss(all(s));
  rep(i, 26) if (char c = 'a' + i; !ss.count(c)) {
    wt(c);
    return 0;
  }
  wt("None");
}
