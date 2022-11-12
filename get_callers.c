#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) 
{
  int call_id = atoi(argv[1]);
  write(1, "Hello World\n", 12);
  if (fork() == 0) {
    write(1, "I am parent\n", 12);
  }
  else {
    write(1, "I am child\n", 11);
    get_callers(call_id);
  }
  wait();
  
  exit();
} 
