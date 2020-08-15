#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s);
  if (s == "RRR") {
    wt(3);
  } else if (s == "SRR" || s == "RRS") {
    wt(2);
  } else if (s == "SSS") {
    wt(0);
  } else {
    wt(1);
  }
}
