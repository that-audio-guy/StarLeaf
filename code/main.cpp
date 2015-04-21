/* Writen by Stephen Baldwin for StarLeaf coding test April 2015 */

/* # main

1. Opens a file stream from location specified in comand line options
2. Decompresses a file stream acording to options
3. Saves output in file at location specified */

#include <iostream>
#include <string>

#include "stream.h"

int main() {
  //string user_input_string;
  std::string str_input_file_name;
  std::cout << "program initiated \n";
  std::cout << "input file name:";
  getline (std::cin, str_input_file_name);
  //stringstream(mystr) >> price;
  std::cout << "input file set to - '" << str_input_file_name << "'" << std::endl;
  /* TODO
  put these user inputs are arguments to the a.out file, typing these each time will get borring!
  */
  //create stream
  Stream LZWFileStream;

  //Stream.LZWFile LZWFileStream();
  //create decompressor
  //note odd naming simulates functional programming
  //Processor.LZWDecompressor LZWDecompress();
  //open stream
  LZWFileStream.openStream(str_input_file_name);
  //create output file
  /*
  LZWFileStream.createOutputFile();
  //stream file from input to output through decompressor
  while(LZWFileStream.dataStillToRead()){
    LZWFileStream.loadNextPacket();
    LZWDecompress.streamPacket(LZWFileStream.packet);
    LZWFileStream.savePacket();
  }
  */
  std::cout << "program ended \n Check file for human readability \n Use different decompression option at runtime if output is garbage \n";
}
