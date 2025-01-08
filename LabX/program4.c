#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {

	//Opening the output file in write mode
	FILE *fp = fopen("program4_output.txt", "w");
	if (fp == NULL) { // If error occurs
		perror("Error opening file");
		return EXIT_FAILURE;
	}

	pid_t pid;

	pid = fork();

	if (pid < 0){ //If error occurs
	
		perror("Fork failed\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) { //Child process
		
		fprintf(fp,"A child process was created with PID: %d and his parent's PID is: %d\n", getpid(), getppid());
	}
	else { //Parent process
		
		wait(NULL);
	}

	if (fclose(fp) != 0) { //If error occurs
		
		perror("Error closing the file");
		return EXIT_FAILURE;
	}

	printf("Data written to program4_output.txt successfully.\n");
	return EXIT_SUCCESS;
}
