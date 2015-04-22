Repo guide
=========

This repo stores the code written by Stephen Baldwin for StarLeaf and their pre job interview code challenge.

# Brief

We would like to give you a small coding task to write a decompressor for the LZW compression algorithm. LZW is relatively simple compression algorithm which was the default compression algorithm on UNIX for a long time and is still used in GIF images and some PDFs.

Wikipedia provides a good description of the algorithm, which you should read. You'll discover that there are a few possible ways to vary the LZW algorithm. We have written a compressor and have attached some compressed data from that compressor that we would like you to decompress. Our compressor used 12-bit fixed with codes padded on the left. So if the encoder was to output the codes 72 followed by 500 it would write out the 3 bytes 00000100 10000001 11110100. If the file is an odd number of bytes the last code is padded to fill 2 whole bytes. i.e. if the last code is 400 then 00000001 10010000 will be written to the stream. The Dictionary was initialised with the 256 values for a byte i.e. with the mapping 0 -> 0, 1->1 etc. up to 256. Once the encoders dictionary was full it reset the dictionary to the initial dictionary and continued adding entries as normal.

The attached zip file contains 4 example compressed files for you to try your decoder on. Each will decompress to some obvious human readable text, so you should be able to easily tell when your decompressor is working. There are no magic numbers or headers on the file so standard tools will not be able to decompress them trivially.

You may use any programming language you like. We code mainly if C++ and python, so if you feel like it pick one of those.

Good Luck!

# Repo contents

- README.ms (this file)
- screenshots (folder)
  - Screenshots of command line print out to guide use and prove it worked on my machine
- Code (folder)
  - The written code
  io_data (folder)
  - Example input (subfolder)
    - (provided by StarLeaf)
  - Example output (subfolder)
    - (produced by this code on my unbuntu machine)

# Repo dependencies

Install c++q11 compiler

# To use the code

1. Download or pull the repo to a clean local directory
2. Open a terminal and navigate to that directory
3. go one layer deeper with cd ./code
3. Type g++ simple_main.cpp -std=c++11 - to compile the code.
4. Type ./a.out
5. view decompressor trace in terminal window if desired
5. use file browser or navigate to io_data/output_files to view decompressed output.

## Input file
Is the input file to be decompressed. Files must follow the naming convention compressedfileX.z where X is defined at compile time.

##  Output files
are placed in the output file folder with the name decompressedfileX.txt with the X being the same as the input file.

# Language choice

Given that functions are being performed on data, so the concepts of objects are unclear, functional programming tools such as f# seem appropriate. My skill with F# is extremely limited (I know of it to a shallow depth rather than have used it). Python and C++ is StarLeaf's preferred languages C++ was thus chosen as it's what I have the most experience with.

# Class structure

I initially looked into 'doing it properly' and having classes.

Given that the file size of the data to decompress could exceed physical memory 'streaming' the data out of the file through the processes seemed sensible hence calling the data storage class 'stream'
In a multi streaming system multiple streams of different types could exist 'stream instances' so again defining this as a class made sense.
The maximisation of code reuse is always desirable so decompressor function is a member of the process class in effect crudely simulating a functional programming structure.

I then ran out of justifiable time and did the modern done thing of using as code from the internet as the base and not first principles. this lead to simple_main.cpp which is the real code to run.

# Result / remaining issues

Output (at least) strongly approaches correct looking. My debugging leans towards input file corruption but I don't have total confidence in that, code is very memory intensive and as such has a fixed file size it can read, given more time this is what i would fix first

- decompressor won't handle situation where the dictionary is completely filled.
- very high memory use but proves concept

in example input file 3 and 4 their appears to be an issue with the input file.
the 'ic' in victory near the start of file 3 is stored as a single value 131, this is less than 256 so not a decompressor issue - input file corrupt

# Time spent

## 20 / 04 / 2015
- 30 mins walking to choir
  - Thought through basic layout needs
- 30 mins walking back from choir
  - Trying to decide if the decompressor should belong to the stream class to keep it simple or the process class to show how I think about potential future code growth and reuse

## 21 / 04 / 2015
- 20 mins walking to tescos and back before breakfast
  - Writing this help documentation (as I was on my phone only).
- 8:30 - 9:00
  - fixing ubuntu wifi driver (again) and copying work so far in atom and markdown from phone friendly google doc. Setting up files.
- 9:00
  - creating GIT repo on github, creating folder tree, loading files into folders ready to stubbing.
- 9:10 - 12:00
  - getting basic text in out of command line working and remembering how to use header files :s stubbed out beginnings of stream.cpp
- 13:00 - 17:30
  - failed to get text output working

## 22 / 04 / 2015
- 8:00-9:00
  - started looking into decompressor
- 10:00 - 12:00
  - output of sorts
- 13:00 - 16:00
  - searching for tiny errors that are causing decompression error
- 16:00 - 17:30
  - small errors in decompressed output remain but cannot spot why in my code from trace output, assume input file corruption.
  - cleaning code
  - updating README
- 17:30 - 18:00
  - Screenshot
  - added 'results' to README.
