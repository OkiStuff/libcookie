cmake_minimum_required(VERSION 3.18)

project(libcookie)
set(source
    src/logger.c
    src/format.c
    src/file.c
    src/realloc.c
    src/foreach.c
)

ADD_LIBRARY(${PROJECT_NAME} static ${source})