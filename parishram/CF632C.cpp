#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 5e4 + 5;

string arr[N];
int n;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  FOR(i, 0, n) {
    cin >> arr[i];
  }
  sort(arr, arr + n, [] (const string &a, const string &b) {
      return a + b < b + a;
      });
  FOR(i, 0, n) {
    cout << arr[i];
  }
  return 0;
}
