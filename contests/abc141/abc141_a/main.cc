#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s);
  vector<string> v = {"Sunny", "Cloudy", "Rainy"};
  rep(i, v.size()) if (v[i] == s) {
    wt(v[(i + 1) % 3]);
    break;
  }
}
