#include<stdio.h>
#include<signal.h>
void catcher(int i){
	printf("signal %d\n", i);
}

main(){
	signal(SIGINT, catcher);
	printf("sleeping\n");
	sleep(20);
}
