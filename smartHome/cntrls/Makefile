#- MM scan source file and makes depends for user made h files
#mbouncingBall

TARGET = tempcontroller
#TARGET = sharedPtrTest
#SOURCES += $(wildcards *.cpp)
SOURCES = $(TARGET).cpp 
SOURCES += 

OBJECTS = $(SOURCES:.cpp=.o)
INC_DIR = ../inc ../../advcpp/inc
LIB_DIR = .
# compiler and linker flags
CC		 =g++
#

LDLIBS = -ldl -ltemp
CPPFLAGS = $(addprefix -I,$(INC_DIR))
CFLAGS   = -g -pedantic -ansi -Wall -Werror -DDEBUG
#for only object
OBJFLAGS = -fPIC -c 
CXXFLAGS += $(CFLAGS) -std=c++03
LDFLAGS  = -g -pthread 
LDFLAGS +=  $(addprefix -L,$(LIB_DIR))

LIB_NAME_1 = 	$(addprefix lib,$(TARGET))
LIB_NAME = 		$(addsuffix .so,$(LIB_NAME_1))

.PHONY: all clean run obj so

all:	$(TARGET) 

$(TARGET): $(OBJECTS)

include depends 

depends: $(SOURCES)
	$(CC) -MM $(CPPFLAGS) $^ > depends

clean:
	rm -f $(TARGET) $(OBJECTS) depends *.gch *.so

run:
	./$(TARGET) -v

obj:
	$(CC) $(CXXFLAGS) $(CPPFLAGS) $(OBJFLAGS) $(SOURCES)

so:
	$(CC) -shared -o $(LIB_NAME) $(OBJECTS)
	
#$ LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/my_library/
#$ export LD_LIBRARY_PATH
