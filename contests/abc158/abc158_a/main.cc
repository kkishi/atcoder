#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  string S;
  cin >> S;
  dbg(S);
  cout << ((S.find("A") != string::npos) && (S.find("B") != string::npos)
               ? "Yes"
               : "No")
       << endl;
}
