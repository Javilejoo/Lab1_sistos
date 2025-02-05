#include <stdio.h>
#include <unistd.h>

int main(){
	int f = fork();
	if(f=0){
	  printf("%d\n", f);
	  int error = execl("./home/javier/Documentos/Lab1_sistos/fork","fork",(char*)NULL);
	}
	else {
	  int error = execl("./home/javier/Documentos/Lab1_sistos/fork","fork",(char*)NULL);
	  printf("%d\n", (int)getpid());
	}
return(0);
}

