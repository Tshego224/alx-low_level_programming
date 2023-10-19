#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generating the assembly code(Intel Syntax) of a C code and saving it in an output file
 *
 * Return: 0
 */

int main(void)
{
	char *CFILE = "main.c";
	char *filename = strdup(CFILE);
	char *basename = strtok(filename, ".");
	char command[100];
	sprintf(command, "gcc -S -masm=intel %s -o %s.s", CFILE, basename);
	int result = system(command);
	if (result == 0) {
        printf("Assembly code generated successfully. Check '%s.s'.\n", basename);
	}
       	else {
        printf("Error: Failed to generate assembly code.\n");
    }
	free(basename);

    return 0;
}
