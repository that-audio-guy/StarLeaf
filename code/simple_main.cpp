#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

int main(){
  std::cout << "Stephen Baldwins LZW 12 fixed width file decompressor \n";
  std::string str_input_file_number;
  std::cout << "input file name ending number \n (same ending appended to output file but with .txt):";
  getline (std::cin, str_input_file_number);

  std::cout << " \n show decompressor trace? y/n:";
  std::string str_show_decompressor_trace;
  getline (std::cin, str_show_decompressor_trace);

  std::ifstream input_file;
  input_file.open("../io_data/input_files/compressedfile" + str_input_file_number + ".z", std::ios::binary);
  bool success = input_file.is_open();
  if (success) {std::cout << "input file opened \n";}

  std::ofstream output_file;
  output_file.open("../io_data/output_files/decompressedfile" + str_input_file_number + ".txt");
  success = output_file.is_open();
  if (success) std::cout << "output file opened \n";

  std::cout << "decompressing \n";
  //read whole file into 32 bit array to get around the 12 not going into 8 problem.
  unsigned int expanded_raw_data[16384]; //hard coded limit will break / not extract whole file
  char three_bytes[3];
  unsigned int index = 0;

  //read three bytes into two spaces in memory
  //this is a very high memory use approach - too much time spent to warrent better solution at this time.
  while (input_file.read(three_bytes,3) && index < 16384) {
    //split into first and last 12 bits
    expanded_raw_data[index]=(three_bytes[0] << 4) + ((three_bytes[1] & 0xF0) >>4);
    index++;
    expanded_raw_data[index]=((three_bytes[1] & 0X0F)<<8) + three_bytes[2];
    index++;
  }
  // code coppied and mildly edited from http://marknelson.us/2011/11/08/lzw-revisited/
  std::unordered_map<unsigned int, std::string> strings;
  for ( int unsigned i = 0 ; i < 256 ; i++ )
    strings[i] = std::string(1,i);
  std::string previous_string;
  unsigned int code;
  unsigned int next_code = 256;
  for(int n=0;n<index;n++){
    code = expanded_raw_data[n];
    if(str_show_decompressor_trace.compare("y") ==0)
      std::cout << "(" << code << "=" << strings[code] << ")";
    output_file << strings[code];
    if ( previous_string.size() ) {//if there was a previous string
      strings[next_code++] = previous_string + strings[code][0];
      if(str_show_decompressor_trace.compare("y")==0)
        std::cout << "['" << previous_string + strings[code][0] << "' -> " << next_code << "]";
    }
    previous_string = strings[code];
  }
  if(str_show_decompressor_trace.compare("y")==0) std::cout << "\n";

  input_file.close();
  std::cout << "input file closed \n";
  output_file.close();
  std::cout << "output file closed \n";
  std::cout << "Done! \n";
}
