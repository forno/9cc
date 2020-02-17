#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
  if (argc != 2) {
    std::cerr << "Invalid arguments\n";
    return 1;
  }

  auto code_p{ argv[1] };
  std::size_t index; // uninitialized
  std::cout <<
    ".intel_syntax noprefix\n"
    ".global main\n"
    "main:\n"
    "  mov rax, " << std::stoul(code_p, &index) << '\n';
  code_p += index;

  while (*code_p != '\0') {
    switch (*code_p) {
    case '+':
      ++code_p;
      std::cout << "  add rax, " << std::stoul(code_p, &index) << '\n';
      code_p += index;
      continue;
    case '-':
      ++code_p;
      std::cout << "  sub rax, " << std::stoul(code_p, &index) << '\n';
      code_p += index;
      continue;
    default:
      std::cerr << "Invalid arguments\n";
      return 1;
    }
  }

  std::cout << "  ret\n";
  return 0;
}
