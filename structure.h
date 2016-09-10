#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifndef _OBJECT_H_
#define _OBJECT_H_

//structure  d object
typedef struct object_t {

    unsigned int type;

    union {

        struct { char *value; } symbol ;
        struct { struct object_t *value;} boolean;
        struct {int         value;} integer;
        struct {char        value;} character;
        struct {char        *value;} string;

        struct {struct object_t *car;
                struct object_t *cdr;} pair;

        struct {struct object_t *value;} empty_list;
    } data ;
} *object;

//Creer proto fonction
#endif
