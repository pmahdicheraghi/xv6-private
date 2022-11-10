#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv) 
{
  if(argc < 2){
    printf(2, "Please enter a valid number\n");
    exit();
  }
  int number = atoi(argv[1]);
  int reg_value;

  __asm__("movl %%edx, %0" : "=r" (reg_value));
//   printf(1, "register old value: %s\n", reg_value);
  __asm__("movl %0, %%edx" :  : "r"(number) );

    printf(1, "Bigest prime number factor: %d\n", prime_number_factor());


  __asm__("movl %0, %%edx" :  : "r"(reg_value));

//   printf(1, "register new value: %s\n", reg_value);

    exit();
} 
