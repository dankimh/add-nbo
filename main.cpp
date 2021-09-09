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

	fseek(fp,0,SEEK_END);
	long sz=ftell(fp);
	rewind(fp);

	uint8_t buffer[sz];

	size_t res=fread(buffer,sizeof(uint8_t),sz,fp);
	
	uint32_t *ret=reinterpret_cast<uint32_t*>(buffer);

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
