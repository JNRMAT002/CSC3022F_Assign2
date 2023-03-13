C = g++
CFLAGS = -std=c++11
SRCS = FrameSequence.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = extractor

all: $(TARGET)

$(TARGET): $(OBJS)
	$(C) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.cpp
	$(C) $(CFLAGS) -c main.cpp

FrameSequence.o: FrameSequence.cpp
	$(C) $(CFLAGS) -c FrameSequence.cpp

clean:
	del /q $(OBJS) $(TARGET).exe
