#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {

	pid_t pid;

	pid = fork();

	if (pid < 0){//If error occurs

		perror("Fork failed");
		return(EXIT_FAILURE);
	}
	else if (pid == 0){ //Child process
		
		//Printing PIDs	
		printf("Child process with PID:%d and parent process with PID:%d\n", getpid(), getppid());

		while(1){
			pause(); //Keeping child alive
		}
	}
	else { //Parent process

		sleep(3); //Sleep for 3 seconds before sending SIGKILL signal 

		printf("Parent sending SIGKILL to child process\n");

		if (kill(pid, SIGKILL) == -1){ //If error occurs
			perror("Kill failed");
			exit(EXIT_FAILURE);
		}
	}

	return(0);
}
