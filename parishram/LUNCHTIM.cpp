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

int n;

void test_case() {
  cin >> n;
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  vector < int > ans(n);
  vector < int > left(n), right(n);
  stack < int > s;
  for (int i = 0; i < n; ++i) {
    while (!s.empty() && a[s.top()] < a[i]) {
      s.pop();
    }
    left[i] = s.empty() ? -1 : s.top();
    s.emplace(i);
  }
  while (!s.empty()) {
    s.pop();
  }
  for (int i = n - 1; i >= 0; --i) {
    while (!s.empty() && a[s.top()] < a[i]) {
      s.pop();
    }
    right[i] = s.empty() ? -1 : s.top();
    s.emplace(i);
  }
  vector < int > dp1(n), dp2(n);
  for (int i = 0; i < n; ++i) {
    if (left[i] == -1 || a[left[i]] != a[i]) {
      dp1[i] = 1;
    } else if (a[left[i]] == a[i]) {
      dp1[i] = dp1[left[i]];
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (right[i] == -1 || a[right[i]] != a[i]) {
      dp2[i] = 1;
    } else if (a[right[i]] == a[i]) {
      dp2[i] += dp2[right[i]];
    }
  }
  debug(left, right, dp1, dp2);
  for (int i = 0; i < n; ++i) {
    if (left[i] == -1 || a[left[i]] != a[i]) {
      --dp1[i];
    }
    if (right[i] == -1 || a[right[i]] != ai[]) {
      --dp2[i];
    }
    cout << dp1[i] + dp2[i] << " ";
  }
  cout << '\n';
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