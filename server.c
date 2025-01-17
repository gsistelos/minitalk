#include "minitalk.h"

static void handle_byte(char byte)
{
	static size_t i;
	static char buffer[BUFFER_SIZE];

	if (byte == '\0')
	{
		buffer[i] = '\n';
		write(STDOUT_FILENO, buffer, i + 1);
		i = 0;
		return ;
	}
	buffer[i] = byte;
	i++;
	if (i == BUFFER_SIZE)
	{
		write(STDOUT_FILENO, buffer, i);
		i = 0;
	}
}

static void signal_handler(int signum)
{
	static char bit;
	static char byte;

	if (signum == SIGUSR1)
		byte |= (1 << bit);
	else if (signum == SIGUSR2)
		byte &= ~(1 << bit);
	bit++;
	if (bit == 8)
	{
		handle_byte(byte);
		bit = 0;
	}
}

static void setup_signals(void)
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
	printf("PID: %d\n", getpid());
	setup_signals();
	while (1)
		;
	return 0;
}
