#- MM scan source file and makes depends for user made h files
#mbouncingBall

TARGET = test9
#TARGET = sharedPtrTest
#SOURCES += $(wildcards *.cpp)
SOURCES = $(TARGET).cpp ../impl/fileInput.cpp
SOURCES += ../../advcpp/noncopy/nonCopyable.cpp ../../advcpp/mutex/mutex.cpp ../../advcpp/thread/thread.cpp ../../advcpp/cond/cond.cpp
SOURCES += ../impl/event.cpp ../impl/iagent.cpp ../impl/absSensor.cpp ../impl/sensors.cpp ../impl/controller.cpp ../impl/router.cpp 
SOURCES += ../impl/id.cpp ../impl/publisher.cpp ../impl/subRegistry.cpp ../impl/ihandle.cpp ../impl/iagent.cpp  ../impl/abscontroller.cpp
SOURCES += ../impl/ilog.cpp ../impl/builder.cpp 

OBJECTS = $(SOURCES:.cpp=.o)
INC_DIR = ../inc ../../advcpp/inc
LIB_DIR = .
# compiler and linker flags
CC		 =g++
#

LDLIBS = -ldl -ltempcontroller -export-dynamic
CPPFLAGS = $(addprefix -I,$(INC_DIR))
CFLAGS   = -g -pedantic -ansi -Wall -Werror -DDEBUG
CXXFLAGS += $(CFLAGS) -std=c++03
LDFLAGS  = -g -pthread 
LDFLAGS +=  $(addprefix -L,$(LIB_DIR))
	
.PHONY: all clean run

all:	$(TARGET) 

$(TARGET): $(OBJECTS)

include depends 

depends: $(SOURCES)
	$(CC) -MM $(CPPFLAGS) $^ > depends

clean:
	rm -f $(TARGET) $(OBJECTS) depends *.gch

run:
	./$(TARGET) -v
