#include "types.h"
#include "user.h"

void waste(int x) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < 50; j++) {
      uptime();
    }
  }
}

void sprintf(char *str, char a, char b, char c, char d, char e) {
  str[0] = a;
  str[1] = b;
  str[2] = c;
  str[3] = d;
  str[4] = e;
  str[5] = '\n';
}

int main() {
  // initialize the semaphores (chopsticks)
  for (int n = 0; n < 5; n++) {
    sem_init(n, 1);
  }

  int n;
  char buf[6];

  for (n = 0; n < 5; n++) {
    if (fork() > 0) {
      while (1) {
        sprintf(buf, '0' + n, '>', '0' + n, ',', '0' + ((n + 1) % 5));
        write(1, buf, 6);

        // take up chopsticks
        sem_acquire(n);
        sem_acquire((n + 1) % 5);
        sprintf(buf, '0' + n, '<', '0' + n, ',', '0' + ((n + 1) % 5));
        write(1, buf, 6);

        waste(5000);

        // put down chopsticks
        sem_release(n);
        sem_release((n + 1) % 5);
        sprintf(buf, '0' + n, '>', '>', '>', '>');
        write(1, buf, 6);
        waste(3000);
      }
    }
  }



  for (; n > 0; n--) {
    wait();
  }

  exit();
}