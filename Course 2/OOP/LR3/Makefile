CC = g++
CFLAGS = -O3 -Wall
LDFLAGS = -lglut -lX11 -lGL -lGLU
SOURCES = main.cpp point.cpp
OBJECT_FILES = $(addprefix obj/, $(SOURCES:.cpp=.o))
EXECUTABLE = LAB3

all: obj $(SOURCES) $(EXECUTABLE)

obj:
	mkdir obj

$(EXECUTABLE): $(OBJECT_FILES) 
	$(CC) $(OBJECT_FILES) $(LDFLAGS) $(CFLAGS) -o $@

obj/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj $(EXECUTABLE)
