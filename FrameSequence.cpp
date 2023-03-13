// FrameSequence Class implementation

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "FrameSequence.h"

namespace JNRMAT002{

    // Default Constructor
    FrameSequence::FrameSequence(void) {
        X1 = 0;
        X2 = 0;
        Y1 = 0;
        Y2 = 0;
        width = 0;
        height = 0;
        operation = "none";
        outputPGMFile = "";
    }

    // Destructor
    FrameSequence::~FrameSequence() {
        // free pixel array
        for (int i = 0; i < height; i++) {
            delete[] pixels[i];
        }
        delete[] pixels;
    }

    // Set start and end points for trajectory
    void FrameSequence::setTrajectory(int X1_arg, int Y1_arg, int X2_arg, int Y2_arg) {
        X1 = X1_arg;
        Y1 = Y1_arg;
        X2 = X2_arg;
        Y2 = Y2_arg;
    }

    // Set size of subframe used in imageSequence
    void FrameSequence::setFrameSize(int width_arg, int height_arg) {
        width = width_arg;
        height = height_arg;
    }

    // Set operation required (i.e., none, reverse, etc.)
    void FrameSequence::setOperation(std::string operation_arg) {
        operation = operation_arg;
    }

    // Set output file name
    void FrameSequence::setOutputName(std::string outputPGMFile_arg) {
        outputPGMFile = outputPGMFile_arg;
    }

    // Read input file and store full image data in array 'pixels'
    unsigned char** FrameSequence::readInputFile(std::string inputPGMFile) {
        
        std::ifstream inputFile(inputPGMFile, std::ios::binary);

        if (!inputFile.is_open()) {
            std::cerr << "Error: could not open PGM file" << std::endl;
            
        }

        std::string line;
        int imgWidth, imgHeight, maxVal = 0;

        // Read/Discard header
        std::getline(inputFile, line);
        int line_count;

        while (std::getline(inputFile, line)) {
            if (line[0] == '#') { continue; }
            else { 
                line_count = 1;
                std::istringstream ss (line);
                ss >> imgWidth >> std::ws >> imgHeight;
                // std::cout << imgWidth << " " << imgHeight << std::endl;
                break; 
            }
        }

        while (std::getline(inputFile, line)) {

            if (line_count == 1) {
                // Get pgm image maxVal
                std::istringstream ss(line);                
                ss >> maxVal;
                line_count += 1;
                // std::cout << maxVal << std::endl;
            }

            if (line_count == 2) {
                // Store pixel data in array | imgHeight = numRows, imgWidth = numCols
                pixels = new unsigned char*[imgHeight];
                for (int i = 0; i < imgHeight; i++) {
                    pixels[i] = new unsigned char[imgWidth];

                    for (int j = 0; j < imgWidth; j++) {
                        inputFile >> pixels[i][j];
                    }
                }

                // inputFile.read( (char*)pixels[0], imgWidth * imgHeight );
                // std::cout << "TEST" << std::endl;
                // break;            
            }            
            
        }

        inputFile.close();
        return pixels;
        // storeFrames(X1, Y1, width, height, pixels);

    

    }

    unsigned char** FrameSequence::storeFrames(int X1, int Y1, int width, int height, unsigned char ** imgData) {
        // std::cout << width << " " << height << " " << X1 << " " << Y1 << std::endl;
        frame = new unsigned char*[height];

        for (int i = 0; i < height; i++) {
            frame[i] = new unsigned char[width];

            for (int j = 0; j < width; j++) {
                frame[i][j] = imgData[Y1+i][X1+j];
            }

        }

        return frame;
        // if (imageSequence.empty()) {
        //     std::cout << "EMPTY" << std::endl;
        // }

        // if (frame != nullptr){
        //     imageSequence.push_back(frame);
        // }
    }

    // No change to imageSequence
    void none() {

    }

    void invert() {

    }
    void reverse() {

    }
    void revinvert() {

    }
}