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

std::vector<int> Matches(const std::string& haystack,
                         const std::string& needle) {
  const long long base = 100000007;
  if (haystack.size() < needle.size()) {
    return {};
  }
  long long h = 0, n = 0, t = 1;
  for (int i = 0; i < needle.size(); ++i) {
    h = h * base + haystack[i];
    n = n * base + needle[i];
    t *= base;
  }
  std::vector<int> matches;
  for (int i = 0;; ++i) {
    if (h == n) matches.push_back(i);
    int j = i + needle.size();
    if (j == haystack.size()) break;
    h = h * base - t * haystack[i] + haystack[j];
  }
  return matches;
}

int main() {
  in(int, n);
  vector<bitset<30>> a(n), b(n);
  rep(i, n) {
    in(int, x);
    a[i] = x;
  }
  rep(i, n) {
    in(int, x);
    b[i] = x;
  }

  vector matches(30, vector(2, vector(n, false)));
  rep(bit, 30) {
    string as, nas, bs;
    rep(i, n) {
      as += '0' + a[i][bit];
      nas += '1' - a[i][bit];
      bs += '0' + b[i][bit];
    }
    bs += bs;
    for (int m : Matches(bs, as)) {
      matches[bit][0][m] = true;
    }
    for (int m : Matches(bs, nas)) {
      matches[bit][1][m] = true;
    }
  }
  vector<pair<int, int>> ans;
  rep(i, n) {
    bool ok = true;
    rep(j, 30) if (!(matches[j][0][i] || matches[j][1][i])) ok = false;
    if (!ok) continue;
    int x = 0;
    rep(j, 30) x |= (matches[j][1][i]) << j;
    ans.push_back({(n - i) % n, x});
  }
  sort(all(ans));
  for (auto [a, b] : ans) out(a, b);
}
