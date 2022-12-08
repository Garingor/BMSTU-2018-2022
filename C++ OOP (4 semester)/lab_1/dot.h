#ifndef OOP_1_DOT_H
#define OOP_1_DOT_H


typedef struct
{
    double x;
    double y;
    double z;
} dot;

int get_dot(dot &copy_dot, int num, dot* &cur_dot);
void offset_dot(dot &cur_dot, dot offset);
void rotate_dot_x(dot &dot, double deg_x);
void rotate_dot_y(dot &dot, double deg_y);
void rotate_dot_z(dot &dot, double deg_z);
void scale_dot(dot &dot, double kx, double ky, double kz);
int check_initial_data_dots(dot* dots, int size);

#endif //OOP_1_DOT_H
