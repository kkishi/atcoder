#include <bits/stdc++.h>

template <typename T>
class SegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  using RangeOperation = std::function<T(T, int)>;

  SegmentTree(
      int size, Operation operation, T identity = T(),
      RangeOperation range_operation = [](int v, int) { return v; })
      : operation_(operation),
        identity_(identity),
        range_operation_(range_operation) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, identity_);
    l_.resize(two * 2 - 1, identity_);
  }

  void Set(int i, T v) {
    int index = v_.size() / 2 + i;
    while (true) {
      v_[index] = v;
      if (index == 0) break;
      v = operation_(v, v_[index + (index % 2 == 0 ? -1 : 1)]);
      index = (index - 1) / 2;
    }
  }
  void Apply(int begin, int end, T v) {
    std::function<void(int, int, int)> rec = [&](int cbegin, int cend,
                                                 int index) {
      if (begin <= cbegin && cend <= end) {
        l_[index] = operation_(l_[index], v);
        return;
      }
      if (cend <= begin || end <= cbegin) {
        return;
      }
      int cmid = (cbegin + cend) / 2;
      rec(cbegin, cmid, index * 2 + 1);
      rec(cmid, cend, index * 2 + 2);
      int size = std::min(cend, end) - std::max(cbegin, begin);
      v_[index] = operation_(v_[index], range_operation_(v, size));
    };
    rec(0, (v_.size() + 1) / 2, 0);
  }

  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    std::function<T(int, int, int)> rec = [&](int cbegin, int cend, int index) {
      int size = std::min(cend, end) - std::max(cbegin, begin);
      if (begin <= cbegin && cend <= end) {
        return operation_(v_[index], range_operation_(l_[index], size));
      }
      if (cend <= begin || end <= cbegin) {
        return identity_;
      }
      int cmid = (cbegin + cend) / 2;
      return operation_(operation_(rec(cbegin, cmid, index * 2 + 1),
                                   rec(cmid, cend, index * 2 + 2)),
                        range_operation_(l_[index], size));
    };
    return rec(0, (v_.size() + 1) / 2, 0);
  }

 private:
  const Operation operation_;
  const T identity_;
  const RangeOperation range_operation_;
  std::vector<T> v_;
  std::vector<T> l_;
};

template <typename T>
SegmentTree<T> AdditiveSegmentTree(int size) {
  auto add = [](T a, T b)->T { return a + b; };
  auto mul = [](T v, int size)->T { return v * size; };
  return SegmentTree<T>(size, add, T(), mul);
}

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
#define DBG(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define DBG(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define CIN(type, ...) \
  type __VA_ARGS__;    \
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
#define COUT(...) write_to_cout(__VA_ARGS__);

#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

int main() {
  CIN(int, N, Q);
  SegmentTree<int> tree = AdditiveSegmentTree<int>(N);
  REP(i, Q) {
    CIN(int, l, r);
    tree.Apply(l - 1, r, 1);
  }
  REP(i, N) cout << tree.Get(i) % 2;
  cout << endl;
}
