#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int fileLength(std::ifstream InFile);

int main(){
	std::ifstream InFile;
	std::string InFileName;

	std::cout << "Enter a file name: ";
	std::cin >> InFileName;
	InFile.open(InFileName.c_str());

	while (InFile.fail()){
		std::cout << "Cannot open " << InFileName << " for reading." << std::endl;
		std::cout << "Enter another file name : ";
		std::cin >> InFileName;
		InFile.open(InFileName.c_str());
	}
	std::cout << "Successfully opened " << InFileName << std::endl;
	std::cout << "Number of lines in file: " << fileLength(InFile) << std::endl;
 
	string strArr[lineCount];

// Read the lines
  char *c_string_word;
  c_string_word = new char [101];
  for (int i=0; i<LineCount; i++){
    InFile.getline(c_string_word, 101);
    strArr[i] = c_string_word;
  }
 	InFile.close();
	return 0;
}

int fileLength(std::ifstream &InFile){
	InFile.clear();
  InFile.seekg(std::ios::beg);

	int lineCount = 0;
	char c;
	InFile.get(c);
	while(!InFile.eof()){
		InFile.get(c);
		if(c == '\n'){
			lineCount++;
		}
	}
	InFile.clear();
  InFile.seekg(std::ios::beg);

  return lineCount;
}