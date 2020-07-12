#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
    void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
    void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                              \
  do {                                        \
cerr << #__VA_ARGS__ << ": ";             \
debug(__VA_ARGS__);                       \
cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
    void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
    void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
    void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

vector<vector<int>> Advance(const vector<int>& group, const string& s) {
  vector<vector<int>> ng(26);
}

int main() {
  in(int, n);
  in(string, s);
  vector<vector<int>> groups(1);
  rep(i, n) groups[0].push_back(i);
  int ans = 0;
  for (int length = 1; length <= n / 2; ++length) {
    vector<vector<int>> ngroups;
    for (
    map<int, vector<int>> m;
    for (int i = 0; i + length - 1 < n; ++i) {
      hashes[i][length] = Hash(hashes[i][length - 1], s[i + length - 1]);
      if (ans == length) continue;
      if (i - length >= 0) {
        m[hashes[i - length][length]].push_back(i - length);
      }
      for (int p : m[hashes[i][length]]) {
        if (s[p + length - 1] == s[i + length - 1]) {
          ans = length;
          break;
        }
        /*
        bool ok = true;
        rep(j, length) if (s[p + j] != s[i + j]) {
          ok = false;
          break;
        }
        if (ok) {
          ans = length;
          break;
        }
        */
      }
    }
  }
  out(ans);
}
