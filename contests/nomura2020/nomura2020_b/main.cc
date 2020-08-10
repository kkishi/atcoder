#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, T);
  rep(i, T.size()) if (T[i] == '?') T[i] = 'D';
  cout << T << endl;
}
