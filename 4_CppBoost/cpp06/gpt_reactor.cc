#include <errno.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <unistd.h>

#include <iostream>

class EventHandler {
   public:
    virtual void handle_event(uint32_t events) = 0;
    virtual int get_fd() const = 0;
};

class Reactor {
   public:
    Reactor() : epoll_fd(epoll_create1(0)) {
        if (epoll_fd == -1) {
            perror("epoll_create1");
            exit(EXIT_FAILURE);
        }
    }

    ~Reactor() { close(epoll_fd); }

    void add_handler(EventHandler* handler, uint32_t events) {
        struct epoll_event ev;
        ev.events = events;
        ev.data.ptr = handler;
        if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, handler->get_fd(), &ev) == -1) {
            perror("epoll_ctl: add");
            exit(EXIT_FAILURE);
        }
    }

    void run() {
        const int MAX_EVENTS = 10;
        struct epoll_event events[MAX_EVENTS];

        while (true) {
            int nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
            if (nfds == -1) {
                if (errno == EINTR) continue;  // interrupted by signal
                perror("epoll_wait");
                exit(EXIT_FAILURE);
            }

            for (int n = 0; n < nfds; ++n) {
                EventHandler* handler =
                    static_cast<EventHandler*>(events[n].data.ptr);
                handler->handle_event(events[n].events);
            }
        }
    }

   private:
    int epoll_fd;
};

class MyEventHandler : public EventHandler {
   public:
    MyEventHandler(int fd) : fd(fd) {}

    void handle_event(uint32_t events) override {
        if (events & EPOLLIN) {
            char buffer[512];
            ssize_t count = read(fd, buffer, sizeof(buffer));
            if (count == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            } else if (count == 0) {
                // End of file
                close(fd);
            } else {
                std::cout << "Read " << count
                          << " bytes: " << std::string(buffer, count)
                          << std::endl;
            }
        }
    }

    int get_fd() const override { return fd; }

   private:
    int fd;
};

int main() {
    int fd = 0;                      // Standard input
    fcntl(fd, F_SETFL, O_NONBLOCK);  // Set non-blocking mode

    MyEventHandler handler(fd);
    Reactor reactor;
    reactor.add_handler(&handler, EPOLLIN);
    reactor.run();

    return 0;
}
