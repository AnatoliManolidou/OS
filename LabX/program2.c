#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int fd[2];
	pid_t pid;
	char buffer[256];
	char msg[] = "This is a messge that the child just recieved from his parent process via pipe()";

	if  (pipe(fd) == -1) { //If error occurs
		perror("Pipe failed");
		return -1;
	}

	pid = fork();

	if (pid < 0){//If error occurs

		perror("Fork failed");
		return(EXIT_FAILURE);
	}
	else if (pid == 0){ //Child process (reads from pipe)

		//Printing PIDs	
		printf("Child process with PID:%d is waiting for a signal via pipe() from parent process with PID:%d.\n", getpid(), getppid());

		close(fd[1]); //Closing the write end of the pipe
		read(fd[0], buffer, sizeof(buffer));
		printf("Child received the following message: \"%s\"  \n", buffer);
		close(fd[0]);
	}
	else { //Parent process sends via pipe

		close(fd[0]); //Closing the red end of the pipe
		write(fd[1], msg, strlen(msg) + 1);
		close(fd[1]);
		wait(NULL); //Waiting for the child to finish
	}

	return(0);
}
