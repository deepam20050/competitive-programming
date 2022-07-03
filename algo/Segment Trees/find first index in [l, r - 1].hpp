// find first index j >= l, such that a[j] >= x
// if no such index then return -1

const int N = 1e5 + 5;
const int inf = 2e9;

int a[N];
int t[N << 2];

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x] = a[lx];
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x] = max(t[2 * x], t[2 * x + 1]);
}

void update (int lx, int rx, int x, int pos, int val) {
  if (lx == rx) {
    t[x] = val;
    return;
  }
  int midx = lx + rx >> 1;
  if (pos <= midx) {
    update(lx, midx, 2 * x, pos, val);
  } else {
    update(midx + 1, rx, 2 * x + 1, pos, val);
  }
  t[x] = max(t[2 * x], t[2 * x + 1]);
}

int find_first_index (int lx, int rx, int x, int ql, int qr, int val) {
  if (t[x] < val) return inf;
  if (ql > rx || lx > qr) {
    return inf;
  }
  if (lx == rx) {
    return lx;
  }
  int midx = lx + rx >> 1;
  if (ql <= lx && rx <= qr) {
    if (t[2 * x] >= val) {
      return find_first_index(lx, midx, 2 * x, ql, qr, val);
    }
    return find_first_index(midx + 1, rx, 2 * x + 1, ql, qr, val);
  }
  return min(find_first_index(lx, midx, 2 * x, ql, qr, val), find_first_index(midx + 1, rx, 2 * x + 1, ql, qr, val));
}