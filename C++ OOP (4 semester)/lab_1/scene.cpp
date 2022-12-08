#include "scene.h"
#include "errors_processing.h"

int check_address_scene(t_QGraphicsScene sc)
{
    int error = SUCCESS;

    if (sc == NULL)
    {
        error = INV_SCENE;
    }

    return error;
}
