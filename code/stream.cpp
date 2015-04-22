#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "stream.h"

  //constructor with default values
  Stream::Stream(std::string input_file_name, std::string output_file_name) {
    std::cout << "Stream constructor called \n";
    input_file.open(input_file_name.c_str(), std::ios::binary);
    bool success = input_file.is_open();
    if (success) {std::cout << "input file opened \n";}

    std::ofstream output_file;
    output_file.open(output_file_name.c_str(), std::ios::binary);
    success = output_file.is_open();
    if (success) {std::cout << "output file opened \n";}

    char packet[1024];
    char test[] = "why does this not work";
    /*
    for(int n=0;n<256;n++){
      packet[n]=n;
    }
    input_file_name = "../io_data/input_files/compressedfile1.z";
    output_file_name = "../io_data/output_files/decompressedfile1.txt";
    //need to use maloc?
    //packet[1024];
    */
  }

  Stream::~Stream(){
    std::cout << "Stream destructor called \n";
    input_file.close();
    output_file.close();
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
    input_file.read(packet,24);
    std::cout << packet << "\n";
    //return success;
  }

  //added decompress in here for speed, not sure having a processor makes sense I I thoght anyhow.
  bool Stream::LZWDecompress() {
/*
Our compressor used 12-bit fixed with codes padded on the left. So if the encoder was to output the codes 72 followed by 500 it would write out the 3 bytes 00000100 10000001 11110100. If the file is an odd number of bytes the last code is padded to fill 2 whole bytes. i.e. if the last code is 400 then 00000001 10010000 will be written to the stream. The Dictionary was initialised with the 256 values for a byte i.e. with the mapping 0 -> 0, 1->1 etc. up to 256. Once the encoders dictionary was full it reset the dictionary to the initial dictionary and continued adding entries as normal.
*/
/*
8 bits in a char
*/
//code taken from http://www.cplusplus.com/articles/iL18T05o/
std::vector<std::vector<char>> dictionary;

    // "named" lambda function, used to reset the dictionary to its initial contents
    const auto reset_dictionary = [&dictionary] {
        dictionary.clear();
        dictionary.reserve(globals::dms);

        const long int minc = std::numeric_limits<char>::min();
        const long int maxc = std::numeric_limits<char>::max();

        for (long int c = minc; c <= maxc; ++c)
            dictionary.push_back({static_cast<char> (c)});
    };

    reset_dictionary();

    std::vector<char> s; // String
    CodeType k; // Key

    while (is.read(reinterpret_cast<char *> (&k), sizeof (CodeType)))
    {
        // dictionary's maximum size was reached
        if (dictionary.size() == globals::dms)
            reset_dictionary();

        if (k > dictionary.size())
            throw std::runtime_error("invalid compressed code");

        if (k == dictionary.size())
            dictionary.push_back(s + s.front());
        else
        if (!s.empty())
            dictionary.push_back(s + dictionary.at(k).front());

        os.write(&dictionary.at(k).front(), dictionary.at(k).size());
        s = dictionary.at(k);
    }

    if (!is.eof() || is.gcount() != 0)
        throw std::runtime_error("corrupted compressed file");

  }

  bool Stream::savePacket() {
    //char packet[64];
    std::cout << packet << "\n";
    output_file.seekp(0);
    output_file.write(packet,24);
    output_file.flush();
    //return success;
  }

  bool Stream::dataStillToRead() {
    return !input_file.eof();
  }
