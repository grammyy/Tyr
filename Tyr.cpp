#include "interpreter.h"

int main(int argc, char* argv[]) {
    interpreter interpreter;
    
    if (argc == 2) {
        interpreter.runFromFile(argv[1]);
    } else {
        interpreter.runInteractiveMode();
    }

    return 0;
}