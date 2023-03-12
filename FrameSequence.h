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
        int X1, Y1, X2, Y2, width, height;
        std::string operation, outputPGMFile;

        // Default Constructor for FrameSequence
        FrameSequence(void);

        // Constructor for FrameSequence
        FrameSequence(int X1, int X2, int Y1, int Y2, int width, int height);

        // Destructor for FrameSequence
        ~FrameSequence();

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