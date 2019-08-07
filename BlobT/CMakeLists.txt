# CMakeList.txt: проект CMake для BlobT; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (BlobT "BlobT.cpp" "BlobT.h")
FILE(GLOB SRC *.cpp)
FILE(GLOB H_FILES *.h)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
