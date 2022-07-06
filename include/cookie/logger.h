#ifndef LIBCOOKIE_LOGGER
#define LIBCOOKIE_LOGGER

#include "bool.h"
#include <stdio.h>

struct _cookie_logger
{
    FILE* file;
    int write_to_file;

    FILE* stdout;
    FILE* stderr;
};

typedef struct _cookie_logger cookie_logger;

cookie_logger cookie_logger_create(int write_to_file, FILE* file);

void cookie_logger_error(cookie_logger* logger, const char* str, const char* func_name, int use_stdout);
void coookie_logger_fatal(cookie_logger* logger, const char* str, const char* func_name, int use_stdout);
void cookie_logger_debug(cookie_logger* logger, const char* str, const char* func_name);
void cookie_logger_success(cookie_logger* logger, const char* str, const char* func_name);
void cookie_logger_info(cookie_logger* logger, const char* str, const char* func_name);

#endif //LIBCOOKIE_LOGGER