// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;

const int N = 1005;

int arr[N];
int t[N];
int l[N];
int r[N];
bitset < N > used[N];

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  FOR(i, 0, m) {
    scanf("%d %d %d", t + i, l + i, r + i);
    if (t[i]) {
      FOR(j, l[i], r[i]) used[j][j + 1] = 1;  
    }
  }
  FOR(i, 0, m) {
    if (!t[i]) {
      FOR(j, l[i], r[i]) {
        if (!used[j][j + 1]) {
          arr[j] = arr[j + 1] + 1;
        }
      }
    }
  }
  arr[n + 1] = 1;
  for (int i = n; i >= 1; --i) arr[i] += arr[i + 1];
  FOR(i, 0, m) {
    bool ok;
    if (t[i]) {
      ok = 1; 
      FOR(j, l[i], r[i]) ok &= arr[j] <= arr[j + 1];
    } else {
      ok = 0;
      FOR(j, l[i], r[i]) ok |= arr[j] > arr[j + 1];
    }
    if (!ok) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  FOR(i, 1, n + 1) printf("%d ", arr[i]);
  return 0;
}