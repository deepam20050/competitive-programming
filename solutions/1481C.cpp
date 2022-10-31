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

const int N = 1e5 + 5;

queue < int > color[N];
int a[N];
int b[N];
int ans[N];
int c[N];

void test_case() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    while (!color[i].empty()) {
      color[i].pop();
    }
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    if (a[i] != b[i]) {
      color[b[i]].emplace(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == b[i]) {
      color[b[i]].emplace(i);
    }
  }
  for (int i = 0; i < m; ++i) {
    cin >> c[i];
  }
  int lastPaint = -1;
  for (int i = m - 1; i >= 0; --i) {
    int x = c[i];
    if (color[x].empty()) {
      if (lastPaint == -1) {
        cout << "NO\n";
        return;
      }
      ans[i] = lastPaint;
    } else {
      int pos = color[x].front();
      if (lastPaint == -1) {
        lastPaint = pos;
      }
      ans[i] = pos;
      a[pos] = x;
      color[x].pop();
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] != b[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << " \n"[i == m - 1];
  }
}

int main() {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}
