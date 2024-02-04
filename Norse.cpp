#include "interpreter.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    interpreter interpreter;
    interpreter.runFromFile(argv[1]);

    return 0;
}