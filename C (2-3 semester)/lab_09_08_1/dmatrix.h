#ifndef LAB_09_DMATRIX_H
#define LAB_09_DMATRIX_H
void detect_min_matrix(int64_t **, int, int, int *, int *);
int delete_min_matrix(int64_t ***, int *, int *);
int delete_line_matrix(int64_t ***, int *, int);
int delete_column_matrix(int64_t **, int, int *, int);
int insert_new_line(int64_t ***, int *, int, int);
int insert_new_column(int64_t ***, int, int *, int);
void transpose_matr(int64_t **matr, int);
void multiplication_matr(int64_t **, int64_t **, int64_t **, int, int);
void copy_matr_to_matr_c(int64_t **, int64_t **, int, int *);
void unit_matrix(int64_t **, int);
void memset_matrix(int64_t **, int);
void exponentiation(int, int, int64_t ***, int, int, int64_t **, int64_t **);
#endif
