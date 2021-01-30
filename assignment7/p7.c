#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/resource.h>
int main(void)
{
        pid_t   pid, ppid;
        int     ruid, rgid, euid, egid, i;
        int     priority;
        char    msg_buf[100];
        int     msg_pipe[2];

        if(pipe(msg_pipe) == -1){
                perror("failed in Parent pipe creation:");
                exit(7);
        }
        printf("\nThis is the Parent process report:\n");
        pid  = getpid();
        ppid = getppid();
        ruid = getuid();
        euid = geteuid();
        rgid = getgid();
        egid = getegid();
        priority = getpriority(PRIO_PROCESS, 0);

        printf("\nPARENT PROG:  Process ID is:\t\t%d\n\
PARENT PROC:  Process parent ID is:\t%d\n\
PARENT PROC:  Real UID is:\t\t%d\n\
PARENT PROC:  Real GID is:\t\t%d\n\
PARENT PROC:  Effective UID is:\t\t%d\n\
PARENT PROC:  Effective GID is:\t\t%d\n\
PARENT PROC:  Process priority is:\t%d\n",
	pid, ppid, ruid, rgid, euid, egid, priority);

	printf("\nPARENT PROC: will now create child, write pipe,\n \
and do a normal termination\n\n");
	sprintf(msg_buf, "This is the pipe message from the parent with PID %d", pid);
	switch(pid = fork()){
	case -1:
	  printf("Call has failed");
	  exit(1);
	default:
     while (msg_buf[i] != '\0') i++;
     write(msg_pipe[1], msg_buf, i);
	   exit(0);
	case 0:
	  printf("This is the Child process report:\n");
	  pid  = getpid();
	  ppid = getppid();
	  ruid = getuid();
	  euid = geteuid();
	  rgid = getgid();
	  egid = getegid();
	  priority = getpriority(PRIO_PROCESS, 0);
          printf("\nCHILD PROG:  Process ID is:\t\t%d\n", pid);
          printf("CHILD PROC:  Process parent ID is:\t%d\n", ppid); 
	  printf("CHILD PROC:  Real UID is:\t\t%d\n", ruid);
          printf("CHILD PROC:  Real GID is:\t\t%d\n", rgid);
          printf("CHILD PROC:  Effective UID is:\t\t%d\n", euid); 
          printf("CHILD PROC:  Effective GID is:\t\t%d\n", egid);
          printf("CHILD PROC:  Process priority is:\t%d\n", priority);
          printf("\nCHILD PROG: about to read pipe and report parent message:\n\n");
	  read(msg_pipe[0], msg_buf, 100);
    printf("PARENT PROG: created Child with %d PID\n", pid);
		printf("CHILD PROC: parent's msg is \n\t%s", msg_buf);
		printf("\nCHILD PROC: Process parent ID now is:   %d\n", getppid());
		printf("CHILD PROC: ### Goodbye ###\n");
		exit(0);
        }
}