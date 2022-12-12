#include "types.h"
#include "user.h"

int main(void)
{
  int n;

  for (n = 0; n < 10; n++) {
    if (fork() > 0) {
      int sum = 0;

      for (int i = 0; i < 99999; i++) {
        for (int j = 0; j < 99999; j++) {
          for (int q = 0; q < 99999; q++) {
            sum += i + j + q;
          }
        }
      }

      printf(1, "%d\n", sum);
    }
  }

  for (; n > 0; n--) {
    wait();
  }

  exit();
}
