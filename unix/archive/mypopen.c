#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	pid_t pid = 0;
	int pipefd[2];
	FILE* output;
	char line[256];
	int status;

	pipe(pipefd);
	pid = fork(); 
	if (pid == 0)
	{
		close(pipefd[0]);
 		dup2(pipefd[1], STDOUT_FILENO);
 		dup2(pipefd[1], STDERR_FILENO);
		execl("popen.c", "cat", (char*)0);
 		//execl("/usr/bin/tail", "/usr/bin/tail", "-f", "popen.c", (char*) NULL);
	}

	close(pipefd[1]);
	output = fdopen(pipefd[0], "r");

	while(fgets(line, sizeof(line), output))
	{
		printf("%s", line);    
	}
	//sleep(3);
	//kill(pid, SIGKILL);
	//waitpid(pid, &status, 0);
	exit(0);
}
