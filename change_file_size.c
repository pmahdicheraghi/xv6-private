#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) 
{
  if(argc < 3){
    printf(2, "invalid number of arguments\n");
    exit();
  }

  char* path = argv[1];
  int length = atoi(argv[2]);

  if (change_file_size(path, length) == 0) {
    printf(1, "file size changed successfully\n");
  } else {
    printf(1, "file size change failed\n");
  }

  exit();
} 
