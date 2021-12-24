CC = clang++
CFLAGS = -Wall --std=c++11

OBJFILES = 

all: main.o $(OBJFILES)
				$(CC) $(CFLAGS) -o main $< $(OBJFILES)


##test: Tests.o $(OBJFILES)
##			$(CC) $(CFLAGS) -o test $< $(OBJFILES)

%.o: %.cpp
				$(CC) -c -o $@ $< $(CFLAGS) 


clean:
				rm *.o main test
							
