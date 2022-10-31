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

typedef long long lli;
typedef pair < int, int > pii;

const int N = 1e5 + 5;

int a[N];
int b[N];
int n;

void test_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n & 1) {
    cout << "NO\n";
    return;
  }
  sort(a, a + n);
  for (int i = 0; i < n / 2; ++i) {
    b[2 * i] = a[i];
  }
  for (int i = 0; i < n / 2; ++i) {
    b[2 * i + 1] = a[i + n / 2];
  }
  bool ok = 1;
  for (int i = 0; i < n; ++i) {
    if (b[i] > b[(i + 1) % n] && b[i] > b[(i + n - 1) % n]) {
      continue;
    }
    if (b[i] < b[(i + 1) % n] && b[i] < b[(i + n - 1) % n]) {
      continue;
    }
    ok = 0;
  }
  if (!ok) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    cout << b[i] << " \n"[i == n - 1];
  }
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