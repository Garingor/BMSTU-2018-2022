#include "operation_list.h"
#include "const.h"
#include "memory_list.h"
#include <stdio.h>
#include <stdlib.h>

void init_descriptor_list(descriptor_list *d)
{
    d->count = 0;
    d->head = NULL;
}

pnode get_last(pnode head)
{
    while (head->next != NULL)
        head = head->next;

    return head;
}

int push_list(descriptor_list *d, int value, int degree)
{
    pnode new = init_new_node();

    if (new == NULL)
    {
        return INV_MALLOC;
    }

    new->value = value;
    new->degree = degree;
    new->next = NULL;

    if (d->head != NULL)
    {
        pnode last_head = get_last(d->head);
        last_head->next = new;
    }
    else
        d->head = new;

    d->count++;

    return SUCCESS;
}

void pop_node(descriptor_list *d)
{
    pnode next = d->head->next;
    free(d->head);
    d->count--;
    d->head = next;
}

void output_list(descriptor_list *d)
{
    int cur_count = 0;
    pnode cur_head = d->head;

    if (cur_head != NULL)
    {
        while (d->count != 0)
        {
            cur_count = 0;
            cur_head = d->head;

            while (cur_count != d->count - 1)
            {
                cur_head = cur_head->next;
                cur_count++;
            }

            printf("%d %d ", cur_head->value, cur_head->degree);

            d->count--;
        }
    }

    printf("1");
}
