#include "memory.h"
#include "output.h"
#include "input.h"
#include "tool.h"
#include "const.h"
#include "menu.h"

int main()
{
    int main_choice = -1;
    int input_matr = 0;
    int input_vector = 0;

    int flag_green_menu = 0;
    int flag_initial_menu = 0;
    int flag_input_matrix_c = 0;
    int flag_input_matrix_s = 0;
    int flag_input_vector_s = 0;

    int **matr_classic = NULL;
    int **vector_classic = NULL;
    int **result = NULL;
    int count_elem = 0;
    double percent_matr = 0.0, percent_vect = 0.0;

    vector *vect = NULL;
    matrix *matr = NULL;
    tja *head = NULL;

    matrix *matr_res = NULL;
    tja *head_res = NULL;

    int n = 0 , m = 1, n_old = 0, m_vector = 0;
    int count_matr = 0, count_vect = 0, count_ja = 0;

    do
    {
        if (flag_green_menu == 1 && flag_initial_menu == 0)
            print_red_uninitial_menu();
        else if (flag_green_menu == 1)
            print_green_menu();
        else
            print_red_menu();

        get_choice(0, 6, &main_choice);

      switch (main_choice)
      {
          case 1:
              n_old = n;
              if (input_size(&n, &m, &m_vector) == SUCCESS)
              {
                  if (matr_classic != NULL)
                      free_matrix_classic(&matr_classic, n_old);
                  if (vector_classic != NULL)
                      free_vector_classic(&vector_classic, m_vector);
                  if (matr != NULL)
                      free_struct_matrix(&matr);
                  if (vect != NULL)
                      free_struct_vector(&vect);
                  if (head != NULL)
                      free_head(&head);
                  if (mem_alloc_matrix_classic(&matr_classic, n, m) != SUCCESS) {
                      free_matrix_classic(&matr_classic, n);
                      return INV_MALLOC_VECTOR_C;
                  }
                  if (mem_alloc_vector_classic(&vector_classic, m_vector) != SUCCESS) {
                      free_vector_classic(&vector_classic, m_vector);
                      return INV_MALLOC_VECTOR_C;
                  }
                  flag_initial_menu = 0;
                  flag_green_menu = 1;
              }
              else
                  flag_green_menu = 0;
              break;

                  case 2:
                  {
                      if (flag_green_menu == 1)
                      {
                          do
                          {
                              print_matrix_menu();

                              get_choice(0, 2, &input_matr);

                              switch (input_matr)
                              {
                                  case 1:
                                      if (flag_input_matrix_c == 1)
                                      {
                                          free_matrix_classic(&matr_classic, n);
                                          if (mem_alloc_matrix_classic(&matr_classic, n, m) != SUCCESS)
                                          {
                                              free_matrix_classic(&matr_classic, n);
                                              return INV_MALLOC_VECTOR_C;
                                          }
                                      }
                                      if (input_matrix_classic(&matr, &head, matr_classic, n, m, &count_matr, &count_ja) == SUCCESS)
                                      {
                                          flag_input_matrix_c = 1;
                                          input_matr = 0;
                                          flag_initial_menu = 1;
                                      }
                                      break;

                                  case 2:
                                      if (flag_input_matrix_s == 1)
                                          free_struct_matrix(&matr);
                                      if (input_matrix_sparse(&matr, &head, matr_classic, n, m, &count_matr, &count_ja) == SUCCESS)
                                      {
                                          flag_input_matrix_s = 1;
                                          input_matr = 0;
                                          flag_initial_menu = 1;
                                      }
                                      break;
                              }

                          } while (input_matr != 0);

                          if (flag_input_matrix_s == 1 || flag_input_matrix_c == 1)
                          {
                              do
                              {
                                  print_vector_menu();

                                  get_choice(0, 2, &input_vector);

                                  switch (input_vector)
                                  {
                                      case 1:
                                          if (flag_input_matrix_c == 1)
                                          {
                                              free_vector_classic(&vector_classic, m_vector);
                                              if (mem_alloc_vector_classic(&vector_classic, m_vector) != SUCCESS)
                                              {
                                                  free_vector_classic(&vector_classic, m_vector);
                                                  return INV_MALLOC_VECTOR_C;
                                              }
                                          }
                                          if (input_vector_classic(&vect, vector_classic, m_vector, &count_vect) == SUCCESS)
                                          {
                                              flag_initial_menu = 1;
                                              input_vector = 0;
                                          }
                                          break;
                                      case 2:
                                          if (flag_input_vector_s == 1)
                                              free_struct_vector(&vect);
                                          if (input_vector_sparse(&vect, vector_classic, m_vector, &count_vect) == SUCCESS)
                                          {
                                              flag_initial_menu = 1;
                                              flag_input_vector_s = 1;
                                              input_vector = 0;
                                          }
                                          break;

                                  }
                              } while (input_vector != 0);
                          }
                      }
                      else
                          printf("\nНевозможно выполнить операцию\nРазмеры не были введены\nПопробуйте снова...\n");
                      break;
                  }


                  case 3:
                      if (flag_green_menu == 1)
                      {
                          if (fill_percent(&percent_matr, &percent_vect) == SUCCESS)
                              flag_green_menu = 1;
                          else
                              break;
                          if (matr_classic != NULL)
                              free_matrix_classic(&matr_classic, n);
                          if (vector_classic != NULL)
                              free_vector_classic(&vector_classic, m_vector);
                          if (matr != NULL)
                              free_struct_matrix(&matr);
                          if (vect != NULL)
                              free_struct_vector(&vect);
                          if (head != NULL)
                              free_head(&head);
                          if (mem_alloc_matrix_classic(&matr_classic, n, m) != SUCCESS)
                          {
                              free_matrix_classic(&matr_classic, n);
                              return INV_MALLOC_VECTOR_C;
                          }
                          if (mem_alloc_vector_classic(&vector_classic, m_vector) != SUCCESS)
                          {
                              free_vector_classic(&vector_classic, m_vector);
                              return INV_MALLOC_VECTOR_C;
                          }
                          if (generate(&matr, &vect, &head, matr_classic, vector_classic, n, m, m_vector, &count_matr, &count_vect,
                                   percent_matr, percent_vect, &count_ja) == SUCCESS)
                              flag_initial_menu = 1;
                          if (head->value == 0)
                              free_head(&head);
                      }
                      else
                          printf("\nНевозможно выполнить операцию\nРазмеры не были введены\nПопробуйте снова...\n");
                      break;

                  case 4:
                      if (flag_green_menu == 1 && flag_initial_menu == 1)
                          print_initial_data(matr, vect, &head, matr_classic, vector_classic, n, m, m_vector, count_matr,
                                  count_vect, count_ja);
                      if (flag_green_menu == 0)
                          printf("\nНевозможно выполнить операцию\nРазмеры не были введены\nПопробуйте снова...\n");
                      else if (flag_initial_menu == 0)
                          printf("\nНевозможно выполнить операцию\nВведите сначала данные\nПопробуйте снова...\n");
                      break;

                  case 5:
                      if (flag_green_menu == 1 && flag_initial_menu == 1)
                      {
                          multiplication_matrix_vector_classic(matr_classic, vector_classic, &result, n, m, &count_elem);
                          result_print(result, n, m, &matr_res, &head_res);
                      }
                      if (flag_green_menu == 0)
                          printf("\nНевозможно выполнить операцию\nРазмеры не были введены\nПопробуйте снова...\n");
                      else if (flag_initial_menu == 0)
                          printf("\nНевозможно выполнить операцию\nВведите сначала данные\nПопробуйте снова...\n");
                      break;

                  case 6:
                      test_memory();
                      break;


      }
  } while (main_choice != 0);

    if (flag_green_menu == 1)
    {
        free_matrix_classic(&matr_classic, n);
        free_vector_classic(&vector_classic, m_vector);
    }
    return SUCCESS;
}
