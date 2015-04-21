#include <iostream>
#include <string>
#include <sstream>

class Stream {

public:

  bool openStream(std::string);
  bool createOutputFile(std::string);
  bool dataStillToRead();
  bool loadNextPacket();
  bool savePacket();
};
