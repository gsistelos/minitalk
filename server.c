#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void print_pid(void)
{
	printf("PID: %d\n", getpid());
}

void signal_handler(int signum)
{
	if (signum == SIGUSR1)
		printf("Received SIGUSR1\n");
	else if (signum == SIGUSR2)
		printf("Received SIGUSR2\n");
	else
		printf("Received signal %d\n", signum);
}

void setup_signals(void)
{
	struct sigaction sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int main(void)
{
	print_pid();
	setup_signals();
	while (1)
		pause();
	return 0;
}
