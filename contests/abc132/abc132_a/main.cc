#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s);
  sort(all(s));
  if (s[0] == s[1] && s[1] != s[2] && s[2] == s[3]) {
    wt("Yes");
  } else {
    wt("No");
  }
}
