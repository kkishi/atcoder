#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, a, b, c);
  wt(a == b && b != c || b == c && c != a || c == a && a != b);
}
