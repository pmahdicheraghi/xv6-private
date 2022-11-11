#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
void create_processes(int n) {
  if(n == 0) return;
  if(fork() == 0) {
    printf(1, "this is my pid: %d\n", getpid());
    printf(1, "Parent pid is %d\n",get_parent_pid());
    create_processes(n - 1);
    wait();
  } 
}

int main(int argc, char *argv[])
{
    create_processes(3);
    wait();
	exit();
}

