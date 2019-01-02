# tukaj napisite seznam izvornih datotek, samo .c dokumente
SOURCE_FILE_LIST = main.cpp creature.cpp window.cpp map.cpp player.cpp skill.cpp level.cpp enemy01.cpp projectile.cpp
# tukaj napisite zeljeno ime programa
TARGET = kom

# tukaj lahko izberete drug prevajalnik
# ce zelite uporabljati C++ zamenjajte 
# gcc z g++
CC = g++

# tukaj bomo kasneje vnesli dodatne knjiznice
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system

CFLAGS = -Wall

OBJECTS = $(SOURCE_FILE_LIST:.c=.o)
all: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $(TARGET) $(LIBRARIES)
debug: CFLAGS += -g
debug: all
clean:
	rm -f $(TARGET) $(OBJECTS)
