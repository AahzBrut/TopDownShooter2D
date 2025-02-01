#include <iostream>
#include "Application/Application.h"


int main(const int argc, char *argv[]) {
    Application application{argc, argv};
    application.Run();
    return EXIT_SUCCESS;
}
