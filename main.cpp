// Main executable - uses FrameSequence Class
// Acquires user input and writes output to appropriate .pgm file
// by Matthew January JNRMAT002

#include <iostream>
#include <string>
#include "FrameSequence.h"

using namespace JNRMAT002;

int main(int argc, char* argv[]) {
    std::string inputPGMFile;
    int X1, Y1, X2, Y2;
    int width, height;
    std::string operation, outputPGMFile;

    std::cout << "You passed " << argc - 1 << " arguments:" << std::endl;
    for (int i = 1; i < argc; i++) {
        
        // std::cout << argv[i] << std::endl;
    }
    return 0;
}
