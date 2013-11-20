#include <iostream>

using namespace std;

int FindLongestSeg(int* a, int n) {
  if (n <= 2) return n;
  bool in_seg = false;
  int max = 0, lo = 2, hi = 2;
  for (int i = 2; i < n; ++i) {
    if (in_seg) {
      if (a[i] != a[i - 1] + a[i - 2]) {
        in_seg = false;
        max = (hi - lo + 1 > max) ? hi - lo + 1 : max;
      } else {
        hi = i;
      }
    } else {
      if (a[i] == a[i - 1] + a[i - 2]) {
        in_seg = true;
        lo = i;
      } else {
        lo = i;
        hi = i;
      }
    }
  }
  if (in_seg) max = (hi - lo + 1 > max) ? hi - lo + 1 : max;
  return max + 2;
}

int main() {
  int n;
  int a[100000 + 10];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << FindLongestSeg(a, n) << endl;
  return 0;
}
