#include <stdio.h>

#include <source.h>

typedef enum {
	SC_ERROR,
	SC_TRANS,
	SC_PROJ,
} start_command;

int main(int argc, char **argv) {
	/* printf("MARKDOWN TO HTML TRANSPILER\n"); */
	/* printf("--VERSION 0.01--\n"); */
	/* printf("Written by Aiden Koorsen\n"); */

	start_command cmd;
	
	if (argc == 2)
		cmd = SC_TRANS;
	else if (argc == 3) 
		cmd = SC_PROJ;
	else
		cmd = SC_ERROR;

	switch (cmd) {
	case SC_ERROR:
		printf("Error -- Invalid input given\n");
		return -1;
		break;
	case SC_TRANS:
		// Transpile a single file
		break;
	case SC_PROJ:
		// Execute a project command
		if (strcmp(argv[1], "new") == 0) {
			printf("Creating a New project\n");

			project p = create_project(argv[2]);
			unload_project(&p);
		}
		break;
	}
	
	return 0;
}
