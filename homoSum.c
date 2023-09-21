#include <stdio.h>
#include <stdlib.h>

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
      scanf("%d", &arr[i]);
    }

    int sum = 0;
    int sign = 0; // +1 for positive, -1 for negative, 0 for zero

    for (int i = 0; i < N; i++) {
      if (sign == 0) {
        sign = arr[i] >= 0 ? 1 : -1;
        sum = arr[i];
      } else if ((sign == 1 && arr[i] >= 0) || (sign == -1 && arr[i] < 0)) {
        sum += arr[i];
      } else {
        printf("%d ", sum);
        sum = arr[i];
        sign = arr[i] >= 0 ? 1 : -1;
      }
    }

    if (sign != 0) {
      printf("%d\n", sum);
    }
  }

  return 0;
}
