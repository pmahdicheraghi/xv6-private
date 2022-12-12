#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) 
{
  if (argc == 2) {
    int ratio = atoi(argv[1]);
    change_global_bjf(ratio, ratio, ratio);
  }
  else if (argc == 4) {
    int pRatio = atoi(argv[1]);
    int aRatio = atoi(argv[2]);
    int cRatio = atoi(argv[3]);
    change_global_bjf(pRatio, aRatio, cRatio);
  }
  else {
    printf(2, "invalid number of arguments\n");
  }
  
  exit();
} 
