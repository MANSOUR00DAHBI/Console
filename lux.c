#include <stdio.h> 
#include <assert.h>
//#include <sys/type.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>

void Read_File(int argc ,  char *argv[] ){
    assert(argc >= 2);
    const char *filepath = argv[1];

    int fd = open(filepath,O_RDONLY);
    assert(fd >= 0);
    struct stat statbuf;
    int err = fstat(fd,&statbuf);
    void *ptr = mmap(NULL ,statbuf.st_size, PROT_READ , MAP_PRIVATE,fd,0);
    assert(ptr != MAP_FAILED);
    close(fd);
    ssize_t n = write(1,ptr,statbuf.st_size );
    assert(n == statbuf.st_size);
     err = munmap(ptr, statbuf.st_size);
    assert(err >= 0 );

      close(fd);

 
}
int main(int argc , char *argv[]){
    
    while(1){
    printf("MiniConsole > \n");
    fgets(argv,sizeof(argv),stdin);
    if(strncmp(argv ,"exit",sizeof(argv))== 0){
	    break;
	    }else if(sscanf(argv,"read %s",argv)==1){
	    Read_File(argc , argv );

	    }else{
	    printf("Unknown Command : %*.s", argv);
	    }
    }

    return 0;
}
	    


