/* Writen by Stephen Baldwin for StarLeaf coding test April 2015 */

/* # main

1. Opens a file stream from location specified in comand line options
2. Decompresses a file stream acording to options
3. Saves output in file at location specified */

#include <iostream>
#include <string>
#include <fstream>

#include "stream.h"
#include "processor.h"

int main() {
  //string user_input_string;
  std::string str_input_file_name;
  std::string str_output_file_name;
  std::cout << "program initiated \n";
  //std::cout << "input file name:";
  //getline (std::cin, str_input_file_name);
  //stringstream(mystr) >> price;
  str_input_file_name = "../io_data/input_files/compressedfile1.z";
  std::cout << "input file set to - '" << str_input_file_name << "'" << std::endl;
  //std::cout << "output file name:";
  //getline (std::cin, str_output_file_name);
  str_output_file_name = "../io_data/output_files/decompressedfile1.txt";
  //stringstream(mystr) >> price;
  std::cout << "output file set to - '" << str_input_file_name << "'" << std::endl;
  /* TODO
  put these user inputs are arguments to the a.out file, typing these each time will get borring!
  */
  //create stream, opening input and output files
  Stream LZWFileStream(str_input_file_name, str_output_file_name);

  //Stream.LZWFile LZWFileStream();
  //create decompressor
  //note odd naming simulates functional programming
  LZWDecompressor LZWDecompress;

  //stream file from input to output through decompressor
  //while(LZWFileStream.dataStillToRead()){
    LZWFileStream.loadNextPacket();

    //LZWDecompress.streamPacket(LZWFileStream.packet);
    LZWFileStream.savePacket();
  //}

  std::cout << "program ended \n Check file for human readability \n Use different decompression option at runtime if output is garbage \n";
}
