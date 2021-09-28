/**************************************************************
 * Problem: OJ ProID
 * Author: 芊枫
 * Date: 2021 Sept 16
 * Algorithm:
 **************************************************************/
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define IINF 0x3f3f3f3f

using namespace std;

inline long long read() {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
template <typename T> inline void write(T x, char ch = '\n', int tim = 0) {
  if (x < 0ll) {
    putchar('-');
    x = -x;
  }
  if (x > 9ll)
    write(x / 10ll);
  putchar(x % 10ll + '0');
  if (tim) {
    for (int i = 1; i <= tim; ++i) {
      putchar(ch);
    }
  }
}

int totN;
long long H[1000005];
long long totANS = 1;
bool flag;

int main() {
  totN = read();
  for (int i = 1; i <= totN; i++)
    H[i] = read();
  if (H[2] >= H[1])
    flag = 1;
  for (int i = 1; i <= totN; i++) {
    if (flag == 0 && i == totN) {
      totANS++;
      break;
    }
    if (flag == 1)
      if (H[i + 1] < H[i]) {
        totANS++;
        flag = 0;
        continue;
      }
    if (flag == 0)
      if (H[i + 1] > H[i]) {
        totANS++;
        flag = 1;
        continue;
      }
  }
  write(totANS);
}
