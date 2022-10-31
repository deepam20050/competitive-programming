// AC
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

const int N = 5e5 + 5;

string arr[N];


int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  FOR(i, 0, n) cin >> arr[i];
  for (int i = n - 2; i >= 0; --i) {
    int x = sz(arr[i]), y = sz(arr[i + 1]);
    bool ok = 0;
    int idx = -1;
    FOR(j, 0, min(x, y)) {
      if (arr[i][j] < arr[i + 1][j]) {
        ok = 1;
        break;
      }
      if (arr[i][j] > arr[i + 1][j]) {
        idx = j - 1;
        break;
      }
    }
    if (!ok) {
      if (idx == -1) {
        while (sz(arr[i]) > sz(arr[i + 1])) arr[i].pop_back();
      } else {
        while (sz(arr[i]) - 1 > idx) {
          arr[i].pop_back();
        }
      }
    }
  }
  FOR(i, 0, n) cout << arr[i] << '\n';
  return 0;
}
