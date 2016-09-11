#include "structure.h"
//ajouter les fichiers avec les proto fonctions



/*variable globale a definir avant le main:
empty_list,true et false*/
object true=TRUE;
object false=FALSE;
object* empty_list=NULL;

object* make_empty_list( void )
{
    return NULL;
}

//object *make_boolean( unsigned int );
object* make_caracter(char carac);
object *make_symbol( char  sym);
object *make_integer( char* num);
object * make_string(char *caractere);
// ...
char get_next_char(char** chaine);

int is_integer(char num)
{
    if (num>=0x30 && num<=0x39)
        return 1;
    else return 0;
}
int is_caracter(char carac)
{
    if(carac>=0x3F  && carac<=0x7A || carac>=0x24 && carac<=0x2D || carac==0x21 ||carac==0x22)
        return 1;
    else return 0;
}
object *read( char * );
//void print( object * );
object *read_atom( char * chaine )
{
    object* atome=NULL;
    char* temp_chaine=chaine;
    char c;

    c=get_next_char(&temp_chaine); //fonction a realiser
    switch(c)   {
    case '#' :
        c=get_next_char(&temp_chaine);
        if(c=='\\' )
        {
            c=get_next_char(&temp_chaine);//probleme sur get next char
            return make_symbol(c);} //attention if symbol ou character
        else
            {
                if (c=='t') return &true;
                else if (c=='f') return &false;
                else return VALUE_ERROR; //erreur invalide atome;
            }
        break;
    case '"' :
        c=get_next_char(&temp_chaine);
        return make_string(temp_chaine);

        break;
    }
    if(is_caractere(c))
    {
        return make_caracter(c);
    }
    else if(is_integer(c))
    {
        return make_integer(temp_chaine);
    }
    else return error;
}
//pour integer faire fonction is int pour voir si il s'agit d'un int ou pas
// prendre en compte les fonctions ou pas


//void print_atom( object * );
object *read_pair( char * );
//void print_pair( object * );
