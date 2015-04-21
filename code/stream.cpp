#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "stream.h"

  //constructor with default values
  //Stream::Stream() {
    /*
    input_file_name = "../io_data/input_files/compressedfile1.z";
    output_file_name = "../io_data/output_files/decompressedfile1.txt";
    //need to use maloc?
    //packet[1024];
    */
  //}

  bool Stream::openStream(std::string input_file_name) {
    std::ofstream input_file;
    input_file.open(input_file_name.c_str());
    bool success = input_file.is_open();
    if (success) {std::cout << "file opened";}
    return success;
  }

  bool Stream::createOutputFile(std::string output_file_name) {
    //return success;
  }

  bool Stream::dataStillToRead() {
    //return b_dataStillToRead;
  }

  bool Stream::loadNextPacket() {
    //return success;
  }

  bool Stream::savePacket() {
    //return success;
  }
