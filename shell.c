#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void prompt (const char *prefix, char *pbuff, size_t size) {
	getcwd(pbuff, size);
	printf("%s%s>>", prefix, pbuff);
}

int main(int argc, char *argv[], char *envp[]) {
	char pbuff[128] = {0};
	char *argv_child[] = {NULL, NULL};
	char *envp_child[] = {NULL};

	argv_child[0] = (char*)malloc(16);

	while(1) {
		char cmd[256] = {0};
		prompt("@@", pbuff, 128);
		scanf("%s", cmd);

		if (strcmp(cmd, "clear") == 0)
		{
			//handle cleanr screen
		}

		strcpy(argv[0], cmd);

		if(fork() != 0) {//father
			int status = 0;
			waitpid(-1, &status, 0);
		} else {
			execve((const char*)cmd, argv_child, envp_child);
		}
	}

return 0;
}
