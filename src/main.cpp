#include <iostream>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // Uncomment this block to pass the first stage
  while(true){
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);
    if(input == "exit 0") {
      return 0;
    } else if(input.find("echo") != std::string::npos){
      int pos = input.find(" ");
      std::string str = input.substr(pos+1);
      std::cout << str << std::endl;

    } else if(input.find("type") != std::string::npos){
      int pos = input.find(" ");
      std::string str = input.substr(pos+1);
      if(str == "echo" || str == "exit" || str == "type"){
        std::cout << str << " is a shell builtin" << std::endl;
      } else {
        std::cout << str << ": not found" << std::endl;
      }
    } else {
      std::cout << input << ": command not found" << std::endl;
    }

  }
  
}
