#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(a, b);
  if (a == b) {
    wt("EQUAL");
  } else if (sz(a) < sz(b) || sz(a) == sz(b) && a < b) {
    wt("LESS");
  } else {
    wt("GREATER");
  }
}
