#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  string s[10];
  s[2] = s[4] = s[5] = s[7] = s[9] = "hon";
  s[0] = s[1] = s[6] = s[8] = "pon";
  s[3] = "bon";
  cout << s[N % 10] << endl;
}
