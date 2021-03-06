#ifndef STREAM_H
#define STREAM_H

class Stream {

private:
  std::ifstream input_file;
  std::ofstream output_file;
  char packet[1024];
  char test[24];

public:

  Stream(std::string input_file_name, std::string output_file_name);
  ~Stream();
  //bool openStream(std::string input_file_name);
  //bool createOutputFile(std::string output_file_name);
  bool dataStillToRead();
  bool loadNextPacket();
  bool LZWDecompress();
  bool savePacket();
};

#endif
