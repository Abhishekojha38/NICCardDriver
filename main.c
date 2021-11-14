#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int create_child(){
	pid_t child_pid = fork();
	int a=0;
		switch(child_pid) {
		case -1:
			printf("Error Case");
			break;

		case 0:
			printf("Child Process\n");
			printf("Calling EXECVP\n");

			char* argument_list[] = {"ls", "-l", NULL}; // NULL terminated array of char* strings
			// Ok! Will execute the command "ls -l"
			auto ret=execvp("ls", argument_list);
			printf("End Calling EXECVP\n");

		default:
			printf("parent process\n");
			a=1;
			break;
		}

	return a;
}

int main(){
printf("Value of function=%d", create_child());
if(1){
	if(1)
		printf("TRUE");
	else
		printf("False");
}
else
	printf("False");


return 0;
}
