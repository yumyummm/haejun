#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int shm_fd = shm_open("/myshm", O_RDWR, 0666); 
    if(shm_fd == -1)
    {
        perror("shm_open");
        exit(1);
    }
    // ftruncate(shm_fd, 4096); 
    char *shm = mmap(0, 4096, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    if(shm==MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }

    printf("Client read: %s\n", shm); //shared memory는 pointer역학을 하기 때문에 이렇게만 써도 됨.
    munmap(shm, 4096);
    return 0;
}
