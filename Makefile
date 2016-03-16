CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES= \
        main.cpp \
				lab.cpp \
				ivanovii.cpp \
				Lysov.cpp


OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=vvm

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o vvm