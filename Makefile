CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=commandLineOptions.cpp objectFactory.cpp main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=terminal_app_template

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm *.o
