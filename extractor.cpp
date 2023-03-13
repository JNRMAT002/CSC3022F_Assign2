// Main executable - uses FrameSequence Class
// Acquires user input and writes output to appropriate .pgm file
// by Matthew January JNRMAT002

#include <iostream>
#include <string>
#include <cstring> // Required to use strcmp()
#include "FrameSequence.h"

using namespace JNRMAT002;

int main(int argc, char* argv[]) {
    // Initialize object of FrameSequence
    FrameSequence frameSequence;

    std::string inputPGMFile;
    int X1, Y1, X2, Y2;
    int width, height;
    std::string operation, outputPGMFile;

    // std::cout << "You passed " << argc - 1 << " arguments:" << std::endl;

    inputPGMFile = argv[1];

    for (int i = 2; i < argc; i++) {
        // Get frame trajectory from input arguments
        if ( strcmp(argv[i], "-t") == 0 ) {
            // std::cout << "test" << std::endl;

            X1 = atoi(argv[i+1]);
            Y1 = atoi(argv[i+2]);
            X2 = atoi(argv[i+3]);
            Y2 = atoi(argv[i+4]);

            i = i + 4;

            frameSequence.setTrajectory(X1, Y1, X2, Y2);
        }

        // Get size of frame from input arguments
        if ( strcmp(argv[i], "-s") == 0 ) {
            width = atoi(argv[i+1]);
            height = atoi(argv[i+2]);

            i = i + 2;

            frameSequence.setFrameSize(width, height);
        }

        // Get required operation and output PGM filename from input arguments
        if ( strcmp(argv[i], "-w") == 0 ) {
            operation = argv[i+1];
            outputPGMFile = argv[i+2];

            i = i + 2;

            frameSequence.setOperation(operation);
            frameSequence.setOutputName(outputPGMFile);

            /*
                SOME CODE HERE TO EXECUTE OPERATION FROM INPUT ARGUMENTS
            */

            unsigned char** imgData = frameSequence.readInputFile(inputPGMFile);
            frameSequence.imageSequence.push_back( frameSequence.storeFrames(X1, Y1, width, height, imgData) );
            // std::cout << frameSequence.imageSequence.size() << std::endl;
           
        }
        
        // std::cout << argv[i] << std::endl;
    }



    std::cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << " " << width << " " << height << " " << operation << " " << outputPGMFile << std::endl;
    return 0;
}
