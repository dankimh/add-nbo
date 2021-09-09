#include<stdio.h>
#include<stdint.h>
#include<stddef.h>
#include<stdlib.h>
#include<netinet/in.h>

uint32_t f(char *a){
	FILE *fp=fopen(a,"rb");
	if(!fp){
		perror("fopen");
		exit(1);
	}

	uint32_t *ret,sz=1;
	size_t res=fread(ret,sizeof(uint32_t),sz,fp);

	return ntohl(*ret);
}
int main(int argc,char *argv[]){
	if(argc!=3){
		printf("Usage : add-nbo <file1> <file2>\n");
		exit(1);
	}
	
	uint32_t a=f(argv[1]);
	uint32_t b=f(argv[2]);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",a,a,b,b,a+b,a+b);
	return 0;
}
