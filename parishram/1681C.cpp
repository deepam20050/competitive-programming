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

const int N = 105;

int a[N], b[N];
int n;
vector < pii > ans;

void solve (int *arr1, int *arr2) {
  for (int i = 0; i < n; ++i) {
    int curr = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr1[j] < arr1[curr]) {
        curr = j;
      }
    }
    if (curr != i) {
      ans.emplace_back(i, curr);
      swap(arr1[i], arr1[curr]);
      swap(arr2[i], arr2[curr]);
    }
  }
}

void test_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  ans.clear();
  solve(a, b);
  solve(b, a);
  if (is_sorted(a, a + n) && is_sorted(b, b + n)) {
    cout << sz(ans) << '\n';
    for (auto [i, j] : ans) {
      cout << i + 1 << " " << j + 1 << '\n';
    }
  } else {
    cout << "-1\n";
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