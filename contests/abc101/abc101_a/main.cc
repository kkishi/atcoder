#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s);
  wt(count(all(s), '+') - count(all(s), '-'));
}
