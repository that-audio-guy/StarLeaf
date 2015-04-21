#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "processor.h"

LZWDecompressor::LZWDecompressor (){
  std::cout << "decompressor constructor called \n";
}

bool LZWDecompressor::streamPacket(){
  return true;
}
