#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "stream.h"

  //constructor with default values
  Stream::Stream(std::string input_file_name, std::string output_file_name) {
    std::cout << "Stream constructor called \n";
    input_file.open(input_file_name.c_str(), std::ios::binary);
    bool success = input_file.is_open();
    if (success) {std::cout << "input file opened \n";}

    std::ofstream output_file;
    output_file.open(output_file_name.c_str());
    success = output_file.is_open();
    if (success) {std::cout << "output file opened \n";}

    char packet[1024];
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
/*
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
  */

  bool Stream::loadNextPacket() {
    //char packet[64];
    input_file.seekg (0, std::ios::beg);
    input_file.read(packet,64);
    std::cout << packet << "\n";
    //return success;
  }

  bool Stream::savePacket() {
    //char packet[64];
    output_file.write(packet,64);
    //return success;
  }

  bool Stream::dataStillToRead() {
    return !input_file.eof();
  }
