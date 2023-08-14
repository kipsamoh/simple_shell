#include "main.h"

/**
 * get_sigint - Hand_le the crtl + c call in pr_ompt
 * @sig: Signal hand_ler
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
