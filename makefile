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

run:
	.\$(TARGET) larger_image.pgm -t 0 10 5000 5000 -s 640 480 -w invert invseq

clean:
	del /q $(OBJS) $(TARGET).exe
