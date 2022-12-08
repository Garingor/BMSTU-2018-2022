#include "model_manager.h"
#include "errors_processing.h"
#include "model.h"

int model_manager(t_choose choose, t_param &param)
{
    static t_model model = init_model();

    int error = SUCCESS;

    switch (choose)
    {
        case LOAD_MODEL:
            error = load_model(model, param.filename);
            break;
        case DRAW_MODEL:
            error = draw_model(model, param.param_draw);
            break;
        case MOVE_MODEL:
            error = move_model(model, param.param_move);
            break;
        case ROTATE_MODEL:
            error = rotate_model(model, param.param_rotate);
            break;
        case SCALE_MODEL:
            error = scale_model(model, param.param_scale);
            break;
        case FREE_MODEL:
            error = free_model(model);
            break;
        default:
            error = ERROR_COMMAND;
            break;
    }
    return error;
}