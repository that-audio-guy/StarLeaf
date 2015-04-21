/* Writen by Stephen Baldwin for StarLeaf coding test April 2015 */

/* # main

1. Opens a file stream from location specified in comand line options
2. Decompresses a file stream acording to options
3. Saves output in file at location specified */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  //string user_input_string;
  string str_input_file_name;
  cout << "program initiated \n";
  cout << "input file name:";
  getline (cin, str_input_file_name);
  //stringstream(mystr) >> price;
  cout << "input file set to " << str_input_file_name << endl;
  /* TODO
  put these user inputs are arguments to the a.out file, typing these each time will get borring!
  */
  /*
  bool b_streamming = false;
  //create stream
  Stream.LZWFile LZWFileStream();
  //create decompressor
  //note odd naming simulates functional programming
  Processor.LZWDecompressor LZWDecompress();
  //open stream
  LZWFileStream.openStream();
  b_streamming = true;
  //create output file
  LZWFileStream.createOutputFile();
  //stream file from input to output through decompressor
  while(b_streamming){
    LZWFileStream.loadNextPacket();
    LZWDecompress.streamPacket(LZWFileStream.packet);
    LZWFileStream.savePacket();
    b_streamming = LZWFileStream.fileNotFullyRead();
  }
  */
  cout << "program ended \n Check file for human readability \n Use different decompression option at runtime if output is garbage";
}
