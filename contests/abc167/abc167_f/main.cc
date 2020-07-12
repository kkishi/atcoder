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

struct S {
  int lowest, change;
  bool operator<(const S& s) const { return lowest > s.lowest; }
};

template <typename T>
bool Setmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  in(int, n);
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  vector<S> left, right;
  for (const string& si : s) {
    int lowest = 0, change = 0;
    for (char c : si) {
      change += c == '(' ? 1 : -1;
      Setmin(lowest, change);
    }
    if (change >= 0) {
      left.push_back({lowest, change});
      continue;
    }
    lowest = 0, change = 0;
    for (int i = si.size() - 1; i >= 0; --i) {
      change += si[i] == ')' ? 1 : -1;
      Setmin(lowest, change);
    }
    right.push_back({lowest, change});
  }
  sort(all(left));
  sort(all(right));
  auto height = [&](const vector<S>& v) -> optional<int> {
    int curr = 0;
    for (const auto& s : v) {
      if (curr + s.lowest < 0) {
        return nullopt;
      }
      curr += s.change;
    }
    return curr;
  };
  optional<int> l = height(left), r = height(right);
  if (l && r && *l == *r) {
    out("Yes");
  } else {
    out("No");
  }
}
