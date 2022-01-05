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

const string opr[] = {"AND", "OR", "XOR"};
const int N = 5005;
const int M = 1005;

string val[N];
int n, m;
array < int, 3 > expr[N];
map < string, int > id;
int arr[N];

int solve (int bit, int x) {
  int cnt = 0;
  arr[0] = x;
  FOR(i, 1, n + 1) {
    if (!val[i].empty()) {
      arr[i] = val[i][bit] - '0';
    } else {
      auto [op1, op2, what] = expr[i];
      int bit1 = arr[op1];
      int bit2 = arr[op2];
      int y;
      if (what == 0) {
        y = (bit1 & bit2);
      } else if (what == 1) {
        y = (bit1 | bit2);
      } else if (what == 2) {
        y = (bit1 ^ bit2);
      }
      arr[i] = y;
    }
    cnt += arr[i];
  }
  return cnt;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  id["?"] = 0;
  FOR(i, 1, n + 1) {
    string s;
    cin >> s;
    id[s] = i;
    string eq;
    cin >> eq;
    string x;
    cin >> x;
    if (x[0] <= '1') {
      val[i] = x;
    } else {
      string op, y;
      cin >> op >> y;
      expr[i] = {id[x], id[y], (int)(find(opr, opr + 3, op) - opr)};
    }
  }
  string ans1(m, '0'), ans2(m, '0');
  FOR(i, 0, m) {
    int c1 = solve(i, 0);
    int c2 = solve(i, 1);
    if (c1 < c2) {
      ans2[i] = '1';
    } else if (c1 > c2) {
      ans1[i] = '1';
    }
  }
  cout << ans1 << '\n' << ans2;
  return 0;
}
