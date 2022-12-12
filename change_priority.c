#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) 
{
  int pid = atoi(argv[1]);
  int newLevel = atoi(argv[2]);

  change_priority(pid, newLevel);

  exit();
} 
