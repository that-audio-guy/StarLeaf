#include stream.h

class Stream {
private:
  std::string input_file_name;
  std::string output_file_name;
  uint packet[1024];

public:
  //constructor with default values
  Stream() {
    input_file_name = "../io_data/input_files/compressedfile1.z";
    output_file_name = "../io_data/output_files/decompressedfile1.txt";
    //need to use maloc?
    //packet[1024];
  }
}

bool openStream(input_file_name) {
  ofstream input_file;
  input_file.open(input_file_name, ios::out | ios::binary);
  bool success = input_file.is_open();
  if (success) {cout << "file opened";}
  return success;

  bool openStream(std::string input_file_name) {
    return success;
  }

  bool createOutputFile(std::string output_file_name) {
    return success;
  }

  bool dataStillToRead() {
    return b_dataStillToRead;
  }

  bool loadNextPacket() {
    return success;
  }

  bool savePacket() {
    return success;
  }
}
