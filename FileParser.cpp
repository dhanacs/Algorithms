#include <map>
#include <set>
#include <stack>
#include <queue>
#include <mutex>
#include <cctype>
#include <vector>
#include <math.h>
#include <thread>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <dirent.h>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <unordered_map>
#include <unordered_set>

class FileParser
{
  public:

  void removeLines()
  {
    string inputFileName = "C:\\Users\\dhana\\Downloads\\CppSample\\sample.txt";
    string outputFileName = "C:\\Users\\dhana\\Downloads\\CppSample\\output.txt";
    string substringToRemove = "(*)";

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    string line;
    while (std::getline(inputFile, line))
    {
      // Check if the line contains the substring to remove.
      if (line.find(substringToRemove) == std::string::npos)
      {
        // If the line does not contain the substring, write it to the output file.
        outputFile << line << std::endl;
      }
    }

    inputFile.close();
    outputFile.close();
  }
};
