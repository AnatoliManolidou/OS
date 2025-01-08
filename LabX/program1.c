#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	for (int count = 0; count < 4; count++){

		pid_t pid;

		//Creating new process
		pid = fork();

		if (pid < 0) { //If an error occurs
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}else if (pid == 0){ //Child process
			if (count == 0)
				printf("PID of the first fork() is: %d, parent: %d\n", getpid(), getppid());
			else if (count == 1)
				printf("PID of the second fork() is: %d, parent: %d\n", getpid(), getppid());
			else if (count == 2)
				printf("PID of the third fork() is: %d, parent: %d\n", getpid(), getppid());
		}else  { //Parent process

			break; // Parent exits => next fork() creates a
			// child that has as his parent the child of the previous fork()
		}
	}

	return(0);
}

