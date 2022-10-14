#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#define FILE_NAME "prime_numbers.txt"
    
int main(int argc, char *argv[])
{
  int low, high, i, flag;
  int temp1 = atoi(argv[1]);
  int temp2 = atoi(argv[2]);
  if (temp1 > temp2){
    low = temp2;
    high = temp1;
  } else{
    low = temp1;
    high = temp2;
  }
  int primeNumberFile = open(FILE_NAME, O_CREATE | O_WRONLY);
   while (low < high) {
      flag = 0;

      if (low <= 1) {
         ++low;
         continue;
      }
      for (i = 2; i <= low / 2; ++i) {

         if (low % i == 0) {
            flag = 1;
            break;
         }
      }

      if (flag == 0)
        printf(primeNumberFile,  "%d ", low);
      ++low;
   }
    printf(primeNumberFile,  "\n", low);
  exit();
}