#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// ------------------------------------------

int
sys_prime_number_factor(void)
{
  struct proc *curproc = myproc();
  int numberREG = curproc->tf->edx;
  int n = numberREG;
  int biggest_prime_factor = 0;
  while(n > 1) {
    if(n == biggest_prime_factor)
      break;
    for (int i = 2; i <= n; i++)
    {
      if (n % i == 0)
      {
        n = n / i;
        if (i > biggest_prime_factor)
        {
          biggest_prime_factor = i;
          break;
        }
      }
    }
  }
  return biggest_prime_factor;
}

int
sys_get_parent_pid(void)
{
  return myproc()->parent->pid;
}

int
sys_proc_info(void)
{
  static char* states[] = {
    [EMBRYO]    "EMBRYO",
    [SLEEPING]  "SLEEP ",
    [RUNNABLE]  "RUNBLE",
    [RUNNING]   "RUNING",
    [ZOMBIE]    "ZOMBIE"
  };

  struct proc* proc = get_proc();
  cprintf("name\t\tpid\tstate\tlevel\tarrival\ttickets\tcycles\tPR\tAR\tCR\trank\n");
  cprintf("---------------------------------------------------------------------------------------------\n");
  for (int i = 0; i < NPROC; i++) {
    if (proc[i].state == UNUSED)
      continue;

    cprintf("%s\t", formatString(proc[i].name));
    cprintf("%d\t%s\t%d\t%d\t%d\t", proc[i].pid, states[proc[i].state], proc[i].priority, proc[i].arrivalTime, proc[i].lotteryTickets);
    cprintf("%s\t", floatToString(proc[i].cycles));
    cprintf("%s\t", floatToString(proc[i].pariorityRatio));
    cprintf("%s\t", floatToString(proc[i].arrivalRatio));
    cprintf("%s\t", floatToString(proc[i].cyclesRatio));
    cprintf("%s\n", floatToString(proc[i].priority * proc[i].pariorityRatio + proc[i].arrivalTime * proc[i].arrivalRatio + proc[i].cycles * proc[i].cyclesRatio));
  }
  return 0;
}
