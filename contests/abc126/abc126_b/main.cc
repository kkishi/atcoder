#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

string str(int x) {
  string ret = "00";
  ret[0] += x / 10;
  ret[1] += x % 10;
  return ret;
}

int main() {
  strings(s);
  bool yymm = false, mmyy = false;
  for (int year = 0; year <= 99; ++year) {
    for (int month = 1; month <= 12; ++month) {
      if (str(year) + str(month) == s) yymm = true;
      if (str(month) + str(year) == s) mmyy = true;
    }
  }
  if (yymm && mmyy) {
    wt("AMBIGUOUS");
  } else if (yymm) {
    wt("YYMM");
  } else if (mmyy) {
    wt("MMYY");
  } else {
    wt("NA");
  }
}
