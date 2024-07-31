#include "SocketIO.h"

#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

SocketIO::SocketIO(int fd) : _fd(fd) {}

SocketIO::~SocketIO() {}

int SocketIO::readn(char* buf, int len) {
    int left = len;
    char* pstr = buf;
    int ret = 0;

    while (left > 0) {
        ret = read(_fd, pstr, left);
        if (-1 == ret && errno == EINTR) {
            continue;
        } else if (-1 == ret) {
            perror("read error -1");
            return -1;
        } else if (0 == ret) {
            break;
        } else {
            pstr += ret;
            left += ret;
        }
    }

    return len - left;
}

int SocketIO::readLine(char* buf, int len) {
    
}

int SocketIO::writen(const char* buf, int len) {}