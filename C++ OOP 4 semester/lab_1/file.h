#ifndef OOP_1_FILE_H
#define OOP_1_FILE_H

#include <cstdio>

typedef FILE* t_stream;
typedef const char* t_filename;

int open_stream(t_stream &stream, t_filename filename);
void close_stream(t_stream &stream);
int check_open_stream(t_stream stream);

#endif //OOP_1_FILE_H
