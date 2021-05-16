CC = g++
TARGET = a.out
OBJS = 12_class_inheritance.o

CXXFLAGS = -g -std=c++17 -Wall
LDFLAGS = -lc

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.c.o :
	$(CC) $(LDFLAGS) -c -o $@ @<

clean :
	rm -rf $(TARGET) $(OBJS)