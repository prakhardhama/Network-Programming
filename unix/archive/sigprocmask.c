#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>

int
main(void)
{
sigset_t set, oset, zero;
pid_t pid;
int code;

sigemptyset(&set);
sigemptyset(&oset);
sigemptyset(&zero);

sigaddset(&set, SIGCHLD);
sigaddset(&set, SIGTERM);

sigprocmask(SIG_BLOCK, &set, &oset);
printf("oset= %x\n", oset);

pid=fork();
if(pid==0)
{
sigsuspend(&zero);
sigprocmask(SIG_SETMASK, NULL, &set);
printf("abc %x\n", set);
exit(1);
}
kill(pid, SIGTERM);
waitpid(pid, &code, 0);
printf("code=%x\n", code);
sigprocmask(SIG_SETMASK, NULL, &set);
printf("xyz %x\n", set);

}


