obj_files = infrastructure/middleware.o infrastructure/middleware_test.o

CC = g++
CFLAGS = -g -w
LD = ld 

all: $(obj_files)

infrastructure/%.o : infrastructure/%.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

test: obj_files
	$(LD) $(obj_files) test 
