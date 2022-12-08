#ifndef LAB_10_TEST_UTILITIES_H
#define LAB_10_TEST_UTILITIES_H

#include "const.h"

#include "./libui/ui.h"

int delete_old_girls(schoolboy ***person, int *count, char *str_error);
int insert_mark(schoolboy **person, int count, char *str_error);
void lower_case_str(char *buffer, char *lower_case);
int check_trash_symbol(char *buffer);
void from_int_to_str(int value, char *str);
void clean_entry(uiEntry *surname, uiEntry *sex, uiEntry *bday,uiEntry *grade);
void input_type_error(char *str_error, char *text);

#endif //LAB_10_TEST_UTILITIES_H
