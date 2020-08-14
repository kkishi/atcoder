#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s);
  sort(all(s));
  wt(s == "abc" ? "Yes" : "No");
}
