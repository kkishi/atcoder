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

string str(int x) {
  string ret = "00";
  ret[0] += x / 10;
  ret[1] += x % 10;
  return ret;
}

int main() {
  in(string, s);
  bool yymm = false, mmyy = false;
  for (int year = 0; year <= 99; ++year) {
    for (int month = 1; month <= 12; ++month) {
      if (str(year) + str(month) == s) yymm = true;
      if (str(month) + str(year) == s) mmyy = true;
    }
  }
  if (yymm && mmyy) {
    out("AMBIGUOUS");
  } else if (yymm) {
    out("YYMM");
  } else if (mmyy) {
    out("MMYY");
  } else {
    out("NA");
  }
}
