#include "my_math.h"
#include <cmath>

double math_sin_angle(double angle)
{
    return sin(angle * PI / 180);
}

double math_cos_angle(double angle)
{
    return cos(angle * PI / 180);
}