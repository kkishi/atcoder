#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(s, c);
  if (c <= s * 2) {
    wt(c / 2);
  } else {
    wt(s + (c - s * 2) / 4);
  }
}
