#include <string.h>
#include <stdio.h>

#include "const.h"
#include "input_output_struct.h"
#include "struct_memory.h"
#include "utilities.h"

#include "./libui/ui.h"
#include "./libui/test/test.h"

static uiWindow *mainwin;
static uiForm *entryForm;
static uiButton *add;
static uiButton *delete;
static uiButton *insert;

static uiEntry *surname;
static uiEntry *sex;
static uiEntry *bday;
static uiEntry *grade;

static int count = 0;
static schoolboy **person = NULL;
static char str_error[100];

static uiTableModelHandler mh;
static uiTableModel *m;
static uiBox *page;

static uiForm *entryForm1;
static uiBox *table;

static int onClosing(uiWindow *w, void *data)
{
    uiQuit();
    return 1;
}

static int onShouldQuit(void *data)
{
    mainwin = uiWindow(data);

    uiControlDestroy(uiControl(mainwin));
    return 1;
}

void delete_table(int count_delete)
{
    for (int j = 0; j < count_delete; j++)
    {
        uiTableModelRowDeleted(m, 0);
    }
}

void print_to_table()
{
    for (int j = 0; j < count; j++)
    {
        uiTableModelRowInserted(m, j);
    }
}

static void onMsgBoxErrorClicked()
{
    uiMsgBoxError(mainwin,"Error", str_error);
}

static int modelNumColumns(uiTableModelHandler *mh, uiTableModel *m)
{
    return 4;
}

static uiTableValueType modelColumnType(uiTableModelHandler *mh, uiTableModel *m, int column)
{
    return uiTableValueTypeString;
}

static int modelNumRows(uiTableModelHandler *mh, uiTableModel *m)
{
    return count;
}

static uiTableValue *modelCellValue(uiTableModelHandler *mh, uiTableModel *m, int row, int col)
{
    char buf[256];
    char str[100];

    switch (col)
    {
        case 0:
            sprintf(buf, "%s", person[row]->surname);
            break;
        case 1:
            sprintf(buf, "%s", person[row]->sex);
            break;
        case 2:
            sprintf(buf, "%s", person[row]->birth);
            break;
        case 3:
            for (int k = 0; k <= person[row]->marks[0]; k++)
            {
                from_int_to_str(person[row]->marks[k], str);
                strcat(buf, " ");
                strcat(buf, str);
            }
            break;
    }
    return uiNewTableValueString(buf);
}

uiBox *maketable(void)
{
    uiTable *t;
    uiTableParams p;

    page = uiNewVerticalBox();

    mh.NumColumns = modelNumColumns;
    mh.ColumnType = modelColumnType;
    mh.NumRows = modelNumRows;
    mh.CellValue = modelCellValue;
    m = uiNewTableModel(&mh);

    memset(&p, 0, sizeof (uiTableParams));
    p.Model = m;
    t = uiNewTable(&p);
    uiBoxAppend(page, uiControl(t), 1);

    uiTableAppendTextColumn(t, "Фамилия",0, uiTableModelColumnNeverEditable, NULL);
    uiTableAppendTextColumn(t, "Пол",1, uiTableModelColumnNeverEditable, NULL);
    uiTableAppendTextColumn(t, "День рождение",2, uiTableModelColumnNeverEditable, NULL);
    uiTableAppendTextColumn(t, "Оценка",3, uiTableModelColumnNeverEditable, NULL);

    return page;
}

void freetable(void)
{
    uiFreeTableModel(m);
}

void add_to_struct(uiButton *b, void *data)
{
    int code_error = SUCCESS;

    char *surname_s = NULL;
    char *sex_s = NULL;
    char *bday_s = NULL;
    char *grade_s = NULL;

    surname_s = uiEntryText(surname);
    sex_s = uiEntryText(sex);
    bday_s = uiEntryText(bday);
    grade_s = uiEntryText(grade);

    code_error = input_struct(&person, &count, surname_s, sex_s, bday_s, grade_s, str_error);

    if (code_error != SUCCESS)
    {
        onMsgBoxErrorClicked();
        return;
    }

    clean_entry(surname, sex, bday, grade);

    delete_table(count - 1);

    print_to_table();
}

void delete_to_struct(uiButton *b, void *data)
{
    int code_error = SUCCESS;
    int copy_count = count;

    code_error = delete_old_girls(&person, &count, str_error);

    if (code_error != SUCCESS)
    {
        onMsgBoxErrorClicked();
        return;
    }

    delete_table(copy_count);

    print_to_table();
}

void insert_to_struct(uiButton *b, void *data)
{
    int code_error = SUCCESS;

    code_error = insert_mark(person, count, str_error);

    if (code_error != SUCCESS)
    {
        onMsgBoxErrorClicked();
        return;
    }

    delete_table(count);

    print_to_table();
}

static uiBox *makeBasicControlsPage(void)
{
    uiBox *vbox = uiNewVerticalBox();
    uiBoxSetPadded(vbox, 1);

    add = uiNewButton("Добавить");
    delete = uiNewButton("Удалить девочек старше 17 лет");
    insert = uiNewButton("Добавить оценку 3");

    uiGroup *group = uiNewGroup("");
    uiGroupSetMargined(group, 1);
    uiBoxAppend(vbox, uiControl(group), 1);

    entryForm = uiNewForm();
    uiFormSetPadded(entryForm, 1);
    uiGroupSetChild(group, uiControl(entryForm));

    uiFormAppend(entryForm,"", uiControl(delete),0);
    uiFormAppend(entryForm,"", uiControl(insert),0);

    uiGroup *group1 = uiNewGroup("");
    uiGroupSetMargined(group1, 1);
    uiBoxAppend(vbox, uiControl(group1), 1);

    entryForm1 = uiNewForm();
    uiFormSetPadded(entryForm1, 1);
    uiGroupSetChild(group1, uiControl(entryForm1));

    surname = uiNewEntry();
    sex = uiNewEntry();
    bday = uiNewEntry();
    grade = uiNewEntry();

    uiFormAppend(entryForm1,"Фамилия", uiControl(surname),0);
    uiFormAppend(entryForm1,"Пол", uiControl(sex),0);
    uiFormAppend(entryForm1,"День рождение", uiControl(bday),0);
    uiFormAppend(entryForm1,"Оценка", uiControl(grade),0);
    uiFormAppend(entryForm1,"", uiControl(add),0);

    return vbox;
}

int main()
{
    uiInitOptions options;

    memset(&options, 0, sizeof (uiInitOptions));
    const char *err = uiInit(&options);
    if (err != NULL)
    {
        fprintf(stderr, "error initializing libui: %s", err);
        uiFreeInitError(err);
        return 1;
    }

    mainwin = uiNewWindow("Лабораторная работа №14", 640, 480, 0);
    uiWindowOnClosing(mainwin, onClosing, NULL);
    uiOnShouldQuit(onShouldQuit, mainwin);

    uiBox *vbox = makeBasicControlsPage();
    table = maketable();

    uiButtonOnClicked(add, add_to_struct, NULL);
    uiButtonOnClicked(delete, delete_to_struct, NULL);
    uiButtonOnClicked(insert, insert_to_struct, NULL);

    uiFormAppend(entryForm,"",uiControl(table),1);

    uiWindowSetChild(mainwin, uiControl(vbox));

    uiWindowSetMargined(mainwin, 0);

    uiControlShow(uiControl(mainwin));
    uiMain();

    freetable();

    free_struct(&person, count);

    return SUCCESS;
}
