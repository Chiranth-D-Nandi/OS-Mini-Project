#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    char  buf[4096];
    int   pulse = 0;

    memset(buf, 'X', sizeof(buf));
    printf("io_pulse: starting\n");
    fflush(stdout);

    for (;;) {
        int fd = open("/tmp/io_pulse.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd >= 0) {
            for (int i = 0; i < 16; i++) write(fd, buf, sizeof(buf));
            close(fd);
        }
        printf("io_pulse: burst %d\n", ++pulse);
        fflush(stdout);
        usleep(500000);   /* 500 ms */
    }
    return 0;
}
