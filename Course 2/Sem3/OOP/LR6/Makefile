CC = g++
CFLAGS = -O3 -c -Wall
LDFLAGS = -lglut -lX11 -lGL -lGLU
SOURCES = circle.cpp ellipse.cpp line.cpp main.cpp point.cpp rectangle.cpp rhombus.cpp triangle.cpp
OBJECT_FILES = $(addprefix obj/, $(SOURCES:.cpp=.o))
EXECUTABLE = LR6

all: obj $(SOURCES) $(EXECUTABLE)

obj:
	mkdir obj

$(EXECUTABLE): $(OBJECT_FILES) 
	$(CC) $(OBJECT_FILES) $(LDFLAGS) -o $@

obj/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj LR6
