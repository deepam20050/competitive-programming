#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 3e4 + 5;

int arr[N], arr2[N];
int n;
int mini;

bool try1 () {
  int j = 0, i = 0;
  FOR(k, 0, n) {
    if (arr[k] == mini) {
      j = k + 1;
      i = k;
      while (j < n && arr[j] != mini) ++j;
      break;
    }
  }
  cout << i << " ";
  FOR(k, 0, j) arr[k] -= mini;
  return is_sorted(arr, arr + i, greater < int > ()) && is_sorted(arr + j, arr + n);
}

void solve () {
  scanf("%d", &n);
  mini = 2e9;
  FOR(i, 0, n) {
    scanf("%d", arr2 + i);
    mini = min(mini, arr2[i]);
    arr[i] = arr2[i];
  }
  bool ok = try1();
  FOR(i, 0, n) arr[i] = arr2[i];
  reverse(arr, arr + n);
  ok &= try1();
  ok ? puts("YES") : puts("NO");
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}