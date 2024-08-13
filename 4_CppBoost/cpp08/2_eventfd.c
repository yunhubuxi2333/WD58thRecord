#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/eventfd.h>
#include <unistd.h>

#define handle_error(msg)   \
    do {                    \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)

int main(int argc, char* argv[]) {
    int efd, j;
    uint64_t u;
    ssize_t s;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <num>...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    efd = eventfd(10, 0);
    if (efd == -1) {
        handle_error("eventfd");
    }

    switch (fork()) {
        case 0:
            // case 0部分是子线程的执行流
            for (j = 1; j < argc; j++) {
                // 打印命令行参数的值
                printf("Child writing %s to efd\n", argv[j]);
                // 将命令行参数从字符串转换为整型
                u = strtoull(argv[j], NULL, 0);

                // write可以写多次，每执行一次，就会执行一次加法
                s = write(efd, &u, sizeof(uint64_t));
                if (s != sizeof(uint64_t)) {
                    handle_error("write");
                }

                sleep(1);
            }
            printf("Child completed write loop\n");

            exit(EXIT_SUCCESS);

        default:
            // 父线程的一个执行流
            sleep(2);

            for (int idx = 2; idx < argc; ++idx) {
                printf("Parent about to read\n");
                // read操作会将计数器的值清零
                s = read(efd, &u, sizeof(uint64_t));
                if (s != sizeof(uint64_t)) {
                    handle_error("read");
                }

                // 将从内核计数器读到的值以不同进制的形式打印出来
                printf("Parent read %llu (0x%llx) from efd\n",
                       (unsigned long long)u, (unsigned long long)u);
                sleep(1);
            }
            exit(EXIT_SUCCESS);

        case -1:
            handle_error("fork");
    }
}