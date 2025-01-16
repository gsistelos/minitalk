#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int validate_args(int argc, char **argv);

int main(int argc, char **argv)
{
	int pid;

	if (validate_args(argc, argv))
		return 1;
	pid = atoi(argv[1]);
	printf("Sending message to PID %d\n", pid);
	return 0;
}
