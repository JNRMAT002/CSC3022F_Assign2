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
        unsigned char** pixels; // Stores original image data
        unsigned char** frame; // Stores frame data to be stored in vector imageSequence
        int X1, Y1, X2, Y2, width, height;
        std::string operation, outputPGMFile;

        // Default Constructor for FrameSequence
        FrameSequence(void);

        // Destructor for FrameSequence
        ~FrameSequence();

        void setTrajectory(int X1, int X2, int Y1, int Y2);
        void setFrameSize(int width, int height);

        unsigned char** readInputFile(std::string inputPGMFile);
        void writeOutputFile(std::vector<unsigned char**> imageSequence);

        // none | invert | reverse | revinvert
        void setOperation(std::string operation);

        // Set name of output file
        void setOutputName(std::string outputPGMFile);

        // Capture frames for imageSequence
        unsigned char** storeFrames(int X1, int Y1, int width, int height, unsigned char ** imgData);

        // All operations HERE *****************
        // std::vector<unsigned char**> none(std::vector<unsigned char**> imageSequence);
        std::vector<unsigned char**> invert(std::vector<unsigned char**> imageSequence);
        std::vector<unsigned char**> reverse(std::vector<unsigned char**> imageSequence);
        std::vector<unsigned char**> revinvert(std::vector<unsigned char**> imageSequence);

        
        
    };
}

#endif