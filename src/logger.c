#include "../include/cookie/logger.h"

cookie_logger cookie_logger_create(int write_to_file, FILE* file)
{
    cookie_logger buffer;

    if (write_to_file == COOKIE_TRUE && file == NULL)
    {
        printf("WARNING IN %s: file is `NULL` and `write_to_file` is `COOKIE_TRUE`... returning struct of `{0}`", __func__);
        return (cookie_logger){0};
    }

    buffer.stdout = stdout;
    buffer.stderr = stderr;
    buffer.write_to_file = write_to_file;
    buffer.file = file;

    return buffer;
}

void cookie_logger_error(cookie_logger* logger, const char* str, const char* func_name, int use_stdout)
{
    FILE* outptr = (use_stdout == COOKIE_TRUE) ? logger->stdout : logger->stderr;
    fflush(outptr);

    fprintf(outptr, "ERROR IN %s: %s", func_name, str);
    if (logger->write_to_file == COOKIE_TRUE) fprintf(logger->file, "ERROR IN %s: %s", func_name, str);
}

