#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) 
{
  if (argc == 3) {
    int pid = atoi(argv[1]);
    int ratio = atoi(argv[2]);
    change_local_bjf(pid, ratio, ratio, ratio);
  }
  else if (argc == 5) {
    int pid = atoi(argv[1]);
    int pRatio = atoi(argv[2]);
    int aRatio = atoi(argv[3]);
    int cRatio = atoi(argv[4]);
    change_local_bjf(pid, pRatio, aRatio, cRatio);
  }
  else {
    printf(2, "invalid number of arguments\n");
  }
  
  exit();
} 
