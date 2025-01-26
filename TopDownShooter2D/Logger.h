#pragma once
#include <chrono>
#include <format>
#include <iostream>
#include <ostream>
#include <string>


#define RESET           "\033[0m"              /* Reset to system default */
#define BOLD_BLACK      "\033[1m\033[30m"      /* Bold Black */
#define BOLD_RED        "\033[1m\033[31m"      /* Bold Red */
#define BOLD_GREEN      "\033[1m\033[32m"      /* Bold Green */
#define BOLD_YELLOW     "\033[1m\033[33m"      /* Bold Yellow */
#define BOLD_BLUE       "\033[1m\033[34m"      /* Bold Blue */
#define BOLD_MAGENTA    "\033[1m\033[35m"      /* Bold Magenta */
#define BOLD_CYAN       "\033[1m\033[36m"      /* Bold Cyan */
#define BOLD_WHITE      "\033[1m\033[37m"      /* Bold White */

#define LOG(M, ...) std::cout << BOLD_BLUE << floor<std::chrono::microseconds>(std::chrono::system_clock::now()) << "(UTC) - INFO: " << std::format(M, ##__VA_ARGS__) << RESET << std::endl

#define LOG_ERR(M, ...) std::cerr << floor<std::chrono::microseconds>(std::chrono::system_clock::now()) << "(UTC) - ERROR: " << std::format(M, ##__VA_ARGS__) << std::endl
