#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(s);
  rep(i, s.size() - 1) if (s[i] == s[i + 1]) {
    wt("Bad");
    return 0;
  }
  wt("Good");
}
