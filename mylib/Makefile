# Makefile for a shared library in C

CC = gcc # C compiler
CFLAGS = -c -fPIC # C flags
LDFLAGS = -shared # Linking flags
TARGET_LIB = libmylib.so # Target library

SRCS = mylib.c
HDRS = $(SRCS:.c=.h)
OBJS = $(SRCS:.c=.o)

.PHONY: clean
clean:
	-$(RM) $(TARGET_LIB) $(OBJS)

.PHONY: all
all: $(TARGET_LIB)
	
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

$(TARGET_LIB): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET_LIB) $(OBJS)	
