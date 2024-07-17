SRCS1	:= $(wildcard *.cpp)
SRCS2	:= $(wildcard *.cc)
TARGETS	:= $(SRCS1:.cpp=)
TARGETS	+= $(SRCS2:.cc=)
CC		:= g++
CFLAGS	:= -Wall -g -std=c++11


default: $(TARGETS)
%:%.cpp
		$(CC) $< -o $@ $(CFLAGS)
%:%.cc
		$(CC) $< -o $@ $(CFLAGS)

.PHONY: clean rebuild default
clean:
		$(RM) $(TARGETS)
rebuild: clean default
