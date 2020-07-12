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

template <typename T>
class Grid {
  template <typename U>
  using pqueue = std::priority_queue<U, std::vector<U>, std::greater<U>>;

 public:
  Grid(int height, int width) : grid_(height, std::vector<T>(width)) {}
  void Set(int row, int col, T value) { grid_[row][col] = value; }
  T Distance(int src_row, int src_col) {
    if (grid_[src_row][src_col] < 0) {
      return -1;
    }
    pqueue<std::tuple<T, int, int>> que;
    que.push(make_tuple(0, src_row, src_col));
    std::map<std::pair<int, int>, T> visited;
    visited[{src_row, src_col}] = 0;
    T ret = 0;
    while (!que.empty()) {
      T dist;
      int row, col;
      std::tie(dist, row, col) = que.top();
      que.pop();
      ret = max(ret, dist);
      int dr[] = {1, -1, 0, 0};
      int dc[] = {0, 0, 1, -1};
      for (int i = 0; i < 4; ++i) {
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if (nrow < 0 || grid_.size() <= nrow || ncol < 0 ||
            grid_[0].size() <= ncol || grid_[nrow][ncol] < 0) {
          continue;
        }
        int ndist = dist + grid_[nrow][ncol];
        const auto it = visited.find({nrow, ncol});
        if (it != visited.end() && it->second <= ndist) {
          continue;
        }
        visited[{nrow, ncol}] = ndist;
        que.push(make_tuple(ndist, nrow, ncol));
      }
    }
    return ret;
  }

 private:
  std::vector<std::vector<T>> grid_;
};

int main() {
  CIN(int,H,W);
  vector<string>m(H);
  REP(i,H)cin>>m[i];

  int ans=0;
  REP(sr,H)REP(sc,W){
    Grid<int> grid(H, W);
    REP(r,H)REP(c,W)grid.Set(r,c,m[r][c]=='.'?1:-1);
    ans=max(ans,grid.Distance(sr,sc));
  }
  COUT(ans);
}
