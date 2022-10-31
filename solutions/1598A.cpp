#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

const int dx8[] = {1, 1, -1, -1, 1, -1, 0, 0};
const int dy8[] = {-1, 1, -1, 1, 0, 0, 1, -1};

string s[2];
int n;
bool used[2][105];

bool check (int x, int y) {
  return 0 <= x && x < 2 && 0 <= y && y < n && s[x][y] == '0';
}

void dfs (int x, int y) {
  used[x][y] = 1;
  for (int i = 0; i < 8; ++i) {
    int x0 = x + dx8[i];
    int y0 = y + dy8[i];
    if (check(x0, y0) && !used[x0][y0]) {
      dfs(x0, y0);
    }
  }
}

void test_case() {
  cin >> n;
  cin >> s[0] >> s[1];
  memset(used, 0, sizeof used);
  if (check(0, 0)) {
    dfs(0, 0);
  }
  used[1][n - 1] ? cout << "YES\n" : cout << "NO\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}