#include "syscall.h"
#include "traps.h"

#define SYSCALL(name) \
  .globl name; \
  name: \
    movl $SYS_ ## name, %eax; \
    int $T_SYSCALL; \
    ret

SYSCALL(fork)
SYSCALL(exit)
SYSCALL(wait)
SYSCALL(pipe)
SYSCALL(read)
SYSCALL(write)
SYSCALL(close)
SYSCALL(kill)
SYSCALL(exec)
SYSCALL(open)
SYSCALL(mknod)
SYSCALL(unlink)
SYSCALL(fstat)
SYSCALL(link)
SYSCALL(mkdir)
SYSCALL(chdir)
SYSCALL(dup)
SYSCALL(getpid)
SYSCALL(sbrk)
SYSCALL(sleep)
SYSCALL(uptime)

// -----------------------------------

SYSCALL(prime_number_factor)
SYSCALL(change_file_size)
SYSCALL(get_callers)
SYSCALL(get_parent_pid)
SYSCALL(proc_info)
SYSCALL(change_priority)
SYSCALL(change_lottery)
SYSCALL(change_local_bjf)
SYSCALL(change_global_bjf)
SYSCALL(sem_init)
SYSCALL(sem_acquire)
SYSCALL(sem_release)
