#include<stdio.h>
#include<fcntl.h>
main(){
	int uid, euid, fdmanoj, fdrahul;

	uid = getuid();
	euid = geteuid();
	printf("uid %d euid %d\n", uid, euid);
	
	fdmanoj = open("/home/manoj/fmanoj", O_RDONLY);
	fdrahul = open("/home/rahul/frahul", O_RDONLY);

	setuid(uid);
	printf("after setuid(%d): uid %d euid %d\n", uid, getuid(), geteuid());

	
	fdmanoj = open("/home/manoj/fmanoj", O_RDONLY);
	fdrahul = open("/home/rahul/frahul", O_RDONLY);
	printf("after setuid(%d): uid %d euid %d\n", uid, getuid(), geteuid());

	setuid(euid);
	printf("after setuid(%d): uid %d euid %d\n", uid, getuid(), geteuid());
}
	
