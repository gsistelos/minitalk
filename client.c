#include "minitalk.h"

static void	send_byte(int pid, char byte)
{
	size_t	bit;

	bit = 0;
	while (bit < 8)
	{
		if (byte & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(SLEEP_TIME);
		bit++;
	}
}

static void	send_message(int pid, char *str)
{
	while (*str)
	{
		send_byte(pid, *str);
		str++;
	}
	send_byte(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (validate_args(argc, argv))
		return (1);
	pid = atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
