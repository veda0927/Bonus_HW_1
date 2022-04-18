#include <assert.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int MAX_CMND = 800;

int main(void)
{
	char *uab_sh_hist = "uab_sh.log";
	FILE *fp = fopen(uab_sh_hist, "w+");

	int off = 0;
	char file_content[MAX_CMND];
	char *cmd = (char *) malloc(MAX_CMND * sizeof(char));

	SHELL:
		printf("uab_sh> ");

		fgets(cmd, MAX_CMND, stdin);
		if (strlen(cmd) == 0) {
			printf("ERROR - Illegal input!\n");
			printf("\tPlease given a valid command...\n");
			goto SHELL;
		}

		memset(file_content, 0, MAX_CMND);
		strcpy(file_content, cmd);
		sprintf(file_content, "> %s", cmd);
		fwrite(file_content, 1, sizeof(file_content), fp);

		cmd[strlen(cmd) - 1] = 0x0;
		char *arg = strtok(cmd, " ");
		if (!strcmp(arg, "list")) {
			struct dirent *dir;
			DIR *d = opendir(".");
			if(d == NULL) {
				printf("ERROR - Unable to read list of files under $PWD\n");
				exit(EXIT_FAILURE);
			}
			while ((dir = readdir(d)) != NULL)
				printf("%s\n", dir->d_name);
			closedir(d);
		} else if (!strcmp(arg, "cd")) {
			arg = strtok(NULL, " ");
			if (chdir(arg) != 0) {
				printf("ERROR - Unable to change directory to %s\n", arg);
				exit(EXIT_FAILURE);
			}
		} else if (!strcmp(arg, "help")) {
			printf("HELP\n----\n");
			printf(" - list    | List all the files in the $PWD\n");
			printf(" - cd $dir | Change the $PWD to the $directory\n");
			printf(" - help    | Display all available commands and their info\n");
			printf(" - quit    | Quit the shell program during runtime\n");
		} else if (!strcmp(arg, "quit")) {
			fclose(fp);
			goto END;
		} else if (!strcmp(arg, "history")) {
			off = ftell(fp);
			fseek(fp, 0, SEEK_SET);
			while(!feof(fp))
				printf("%c", fgetc(fp));
			fseek(fp, off, SEEK_SET);
		} else if (!strcmp(arg, "hello")) {
			pid_t process_id = fork();
			if (process_id == 0)
				exit(execlp("../bin/hello", strtok(NULL, " "), NULL, (char *) NULL));
			waitpid(process_id, NULL, 0);
		} else if (!strcmp(arg, "fibonacci")) {
			pid_t process_id = fork();
			if (process_id == 0)
				exit(execlp("../bin/fibonacci", strtok(NULL, " "), NULL, (char *) NULL));
			waitpid(process_id, NULL, 0);
		} else {
			fprintf(stderr, "ERROR - No such command: %s\n", arg);
		}

		goto SHELL;
	
	END:
		free(cmd);
		return EXIT_SUCCESS;
}
