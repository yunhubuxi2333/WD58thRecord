SRCS:=$(wildcard *.cc)
EXES:=$(SRCS:%.cc=%)
all:$(EXES)
%:%.cc
	g++ $^ -o $@ -lwfrest -lworkflow -g
