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

template <typename T>
bool Setmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  in(int, D);
  vector<int> c(26);
  rep(i, 26) cin >> c[i];
  vector<vector<int>> s(D, vector<int>(26));
  rep(i, D) rep(j, 26) cin >> s[i][j];

  int sat = 0;
  vector<int> last(26);
  rep(i, D) {
    int d = i + 1;
    int maxi = numeric_limits<int>::min();
    int chosen;
    rep(j, 26) {
      int change = s[i][j];
      rep(k, 26) {
        int last_day = k == j ? d : last[k];
        change -= c[k] * (d - last_day);
      }
      // HACK
      change += (d - last[j]) * c[j] * 6;
      if (Setmax(maxi, change)) {
        chosen = j;
      }
    }
    last[chosen] = d;
    sat += maxi;
    dbg(sat, maxi, chosen);
#if DEBUG
    rep(i, 26) {
      if (i) cerr << " ";
      cerr << last[i];
    }
    cerr << endl;
#endif
    out(chosen + 1);
  }
  dbg(max(1000000 + sat, 0));
}
