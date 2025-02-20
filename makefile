.PHONY: all clean 

# Name of the executable
EXE= lux

# All object files
OBJS= lux.o 

# Compiler
CC= gcc

CFLACS= -Wall -g


# Linker flags 
LDFLAGS = -lm

# Default target
all: $(EXE)

# link the executable  
$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
# Compiler source files	
%.o: %.c
	$(CC) $(CFLACS) -c $< -o $@ 

# clean up
clean:
	rm -rfv $(EXE) $(OBJS)







