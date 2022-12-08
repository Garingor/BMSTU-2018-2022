#include <stdio.h>
#include "const.h"
#include "menu.h"

int main()
{
    int main_choice = -1;

    do
    {
        print_menu();

        get_choice(0, 8, &main_choice);

        switch (main_choice)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
        }
    } while (main_choice != 0);

    return SUCCESS;
}
