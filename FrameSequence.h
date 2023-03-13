/*
    Matthew January JNRMAT002
    Header file for video builder assignment (Assignment 2)
    FrameSequence Class definition
*/
#ifndef MY_VIDEO_BLDR_H
#define MY_VIDEO_BLDR_H

// Includes
#include <vector>
#include <string>

namespace JNRMAT002 {
    class FrameSequence {
    public:        
        std::vector<unsigned char **> imageSequence;
        unsigned char** pixels;
        int X1, Y1, X2, Y2, width, height;
        std::string operation, outputPGMFile;

        // Default Constructor for FrameSequence
        FrameSequence(void);
        
        // Destructor for FrameSequence
        ~FrameSequence();

        void setTrajectory(int X1, int X2, int Y1, int Y2);
        void setFrameSize(int width, int height);

        void readInputFile(std::string inputPGMFile);

        // none | invert | reverse | revinvert
        void setOperation(std::string operation);

        // All operations HERE *****************
        void none();
        void invert();
        void reverse();
        void revinvert();

        // Set name of output file
        void setOutputName(std::string outputPGMFile);


        
    private:
        
    };
}

#endif