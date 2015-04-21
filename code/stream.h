#ifndef STREAM_H
#define STREAM_H

class Stream {

private:
  std::ifstream input_file;
  std::ofstream *output_file;
  unsigned int packet[1024];

public:

  Stream(std::string input_file_name);
  bool openStream(std::string input_file_name);
  bool createOutputFile(std::string output_file_name);
  bool dataStillToRead();
  bool loadNextPacket();
  bool savePacket();
};

#endif
