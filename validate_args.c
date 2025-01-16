#include <ctype.h>
#include <string.h>
#include <stdio.h>

static int is_int_overflow(const char *str)
{
	size_t len;

	if (*str == '+')
		str++;
	while (*str && *str == '0')
		str++;
	len = strlen(str);
	if (len > 10 || (len == 10 && strcmp(str, "2147483647") > 0))
		return 1;
	return 0;
}

static int is_positive_number(const char *str)
{
	size_t i;

	if (str[0] == '+')
		i = 1;
	else
		i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

int validate_args(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <pid> <message>\n", argv[0]);
		return 1;
	}
	if (!is_positive_number(argv[1]))
	{
		fprintf(stderr, "Invalid PID: not a positive number: %s\n", argv[1]);
		return 1;
	}
	if (is_int_overflow(argv[1]))
	{
		fprintf(stderr, "Invalid PID: integer overflow: %s\n", argv[1]);
		return 1;
	}
	return 0;
}
