#ifndef MINITALK_H
#define MINITALK_H

#define BUFFER_SIZE 1024
#define SLEEP_TIME 200

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int validate_args(int argc, char **argv);

#endif
