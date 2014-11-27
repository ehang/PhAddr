CC = gcc                          #编译器
CFLAGS +=                         #编译选项
LDFLAGS +=                        #链接选项
EXEC = phaddr.exe                   #生成的可执行文件

all: $(EXEC)

.PHONY: all

$(EXEC): main.o phaddr.o
	$(CC) $(CFLAGS) $(LDFLAGS) main.o phaddr.o -o $@

main.o: main.c phaddr.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o main.o main.c

phaddr.o: phaddr.c phaddr.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o phaddr.o phaddr.c

clean:
	-rm -f $(EXEC) *.gdb *.o *.a

.PHONY: clean
