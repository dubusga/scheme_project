#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//structure  d object
typedef struct object_t {

    unsigned int type;

    union {

        struct { char *value; } symbol ; //notation #\hj
        struct { struct object_t *value;} boolean; //notation #t ou #f
        struct {int         value;} integer;
        struct {char        value;} character;
        struct {char        *value;} string;    //commence par un "

        struct {struct object_t *car;
                struct object_t *cdr;} pair; //constituant de la liste car ->pointeur sur atome et suite de la liste

        struct {struct object_t *value;} empty_list;
    } data ;
} *object;

