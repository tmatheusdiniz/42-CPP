#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int v, char** s)
{
	int	fd[2];
	if (pipe(fd) == -1)
	{
		exit(1);
		perror("pipe");
	}
	pid_t pid = fork();
	if (pid == -1) { perror("fork"); exit(1); }
	if (pid == 0)
	{
		close (fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execvp(s[1], NULL); // NULL til I decide
		_exit(127);
	}
	
}
