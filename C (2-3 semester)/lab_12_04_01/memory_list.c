#include "memory_list.h"
#include "const.h"
#include <stdlib.h>

pnode init_new_node()
{
    pnode new = NULL;

    new = malloc(sizeof(node));

    return new;
}

void free_list(descriptor_list *d)
{
    pnode copy;
    if (d->head != NULL)
    {
        while (d->head->next != NULL)
        {
            copy = d->head->next;
            free(d->head);
            d->head = copy;
        }
        free(d->head);
    }
}
