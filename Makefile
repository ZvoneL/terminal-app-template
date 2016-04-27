TARGET   = terminal_app_template
SOURCES  = $(shell echo *.cpp)
HEADERS  = $(shell echo *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

CC=g++
CFLAGS=-c -Wall
LDFLAGS=

all: $(SOURCES) $(TARGET)

debug: CFLAGS += -g -O0 -Wextra
debug: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
    
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
    
clean:
	rm -f $(TARGET) *.o

.PHONY : all debug clean
