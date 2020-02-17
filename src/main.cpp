#include <iostream>
#include <string>

int main(int argc, char** argv)
{
  if (argc != 2) {
    std::cerr << "Invalid arguments\n";
    return 1;
  }

  std::cout << ".intel_syntax noprefix\n"
               ".global main\n"
               "main:\n"
               "  mov rax, " << std::stoi(argv[1]) << '\n' <<
               "  ret\n";
  return 0;
}
