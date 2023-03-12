// FrameSequence Class implementation

#include <vector>
#include <string>
#include "FrameSequence.h"

using namespace JNRMAT002;

// Default Constructor
FrameSequence::FrameSequence() {
    // int X1, int X2, int Y1, int Y2, int width, int height
    X1 = 0;
    X2 = 0;
    Y1 = 0;
    Y2 = 0;
    width = 0;
    height = 0;
}

// Constructor w/ vars from input arguments
FrameSequence::FrameSequence(int X1_arg, int Y1_arg, int X2_arg, int Y2_arg, int width_arg, int height_arg) {
    X1 = X1_arg;
    Y1 = Y1_arg;
    X2 = X2_arg;
    Y2 = Y2_arg;
    width = width_arg;
    height = height_arg;

}

// Destructor
FrameSequence::~FrameSequence() {

}

void FrameSequence::setOperation(std::string operation_arg) {
    operation = operation_arg;
}

// No change to imageSequence
void none() {

}