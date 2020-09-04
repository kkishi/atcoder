#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  int a, b;
  char op;
  cin >> a >> op >> b;
  wt(a + (op == '+' ? b : -b));
}
