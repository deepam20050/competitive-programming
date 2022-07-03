void push (int lx, int rx, int x) {
  if (!sum[x]) return;
  t[x] += sum[x];
  if (lx != rx) {
    sum[2 * x] += sum[x];
    sum[2 * x + 1] += sum[x];
  }
  sum[x] = 0;
}

void update (int lx, int rx, int x, int ql, int qr, int v) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return;
  if (ql <= lx && rx <= qr) {
    sum[x] += v;
    push(lx, rx, x);
    return;
  }
  int midx = lx + rx >> 1;
  update(lx, midx, 2 * x, ql, qr, v);
  update(midx + 1, rx, 2 * x + 1, ql, qr, v);
  t[x] = max(t[2 * x], t[2 * x + 1]);
}

int find_kth_one (int lx, int rx, int x, int ql, int v) {
  push(lx, rx, x);
  if (t[x] < v) return -1;
  if (ql > rx) return -1;
  if (lx == rx) {
    return lx;
  }
  int midx = lx + rx >> 1;
  int ansl = find_kth_one(lx, midx, 2 * x, ql, v);
  return ansl != -1 ? ansl : find_kth_one(midx + 1, rx, 2 * x + 1, ql, v);
}
