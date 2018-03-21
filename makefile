#
# PROGRAM: Assign 6   
# PROGRAMMER: Samuel Piecz 
# LOGON ID: Z1732715 
# DATE DUE: 03/22/18 
#
# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment6: assignment5.o	assignment6.o	assignment6main.o
	g++ $(CCFLAGS) -o assignment6.exe assignment6.o assignment5.o assignment6main.o

# Rule to compile source code file to object code
assignment5.o: assignment5.cc	assignment5.h
	g++ $(CCFLAGS) -c assignment5.cc

# Rule to compile source code file to object code
assignment6.o: assignment6.cc	assignment6.h
	g++ $(CCFLAGS) -c assignment6.cc

# Rule to compile source code file to object code
assignment6main.o: assignment6main.cc
	g++ $(CCFLAGS) -c assignment6main.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm -f *.o assignment6.exe
