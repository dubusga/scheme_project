#include "structure.h"


//fonctions

/*variable globale a definir :
empty_list,true et false*/

object *make_empty_list( void );
object *make_boolean( unsigned int );

object *make_symbol( char * );
object *make_integer( int );
// ...

object *read( char * );
void print( object * );
object *read_atom( char * );
/* c=get_next_char();
    switch(c){
    case '#' : c=get_next_char;
            if("\"==c) /essayer de créer un caractère
            else /creer un booleen
            break;
    case " " :
    */
void print_atom( object * );
object *read_pair( char * );
void print_pair( object * );
