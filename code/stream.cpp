#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "stream.h"

  //constructor with default values
  Stream::Stream(std::string input_file_name) {
    std::cout << "Stream constructor called \n";
    input_file.open(input_file_name.c_str());
    bool success = input_file.is_open();
    if (success) {std::cout << "file opened \n";}
    /*
    input_file_name = "../io_data/input_files/compressedfile1.z";
    output_file_name = "../io_data/output_files/decompressedfile1.txt";
    //need to use maloc?
    //packet[1024];
    */
  }

/*
  bool Stream::openStream(std::string input_file_name) {
    //std::ifstream input_file;
    input_file->open(input_file_name.c_str());
    bool success = input_file->is_open();
    if (success) {std::cout << "file opened \n";}
    return success;
  }
  */

  bool Stream::createOutputFile(std::string output_file_name) {
    std::ofstream output_file;
    output_file.open(output_file_name.c_str());
    bool success = output_file.is_open();
    if (success) {
      std::cout << "file opened \n";
      output_file << output_file_name.c_str();
      }
    return success;
  }

  bool Stream::dataStillToRead() {
    return !input_file.eof();
  }

  bool Stream::loadNextPacket() {
    //return success;
  }

  bool Stream::savePacket() {
    //return success;
  }
