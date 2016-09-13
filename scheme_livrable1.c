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
object* make_caracter(char carac)// fonction bancale
{
	return &carac;
}
object *make_symbol( char  sym)
{
	object symbole;
	symbole="#\";
	symbole=strcat(symbole,&sym);
	return &symbole;
}
object *make_integer( char* num, char c)
{
	object integer=0;
	char next;
	integer = atoi(&c);
	next=get_next_char(&num);
	while (next>=0x30 && next<=0x39)
	{
		integer=integer*10+atoi(&next);
		next=get_next_char(&num);
	}
	return &integer;
}

//char** s'il faut modif le pointeur de chaine
object * make_string(char *caractere)
{
	object chaine=NULL;
	char c=get_next_char(&caractere);
	while (is_caracter(c))
	{	
		chaine=strcat(chaine, &c);
	}
	return &chaine;
}


char get_next_char(char** chaine)
{	char c;
	//on prend le caractere suivant de celui marque par chaine
	*chaine=*chaine+1; //verif les pointeurs
	c=**chaine;
	if (c=' ') return get_next_char(chaine);
	else	return c;
} //code pas optimal

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

//voir s'il ne faut pas mettre un char** pour avoir la valeur de fin du pointeur sur la sexpr
object *read_atom( char * chaine )//depend de la definition de chaine est ce que il y a parenthese
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
        return make_string(temp_chaine);

        break;
    }
    if(is_caractere(c))
    {
        return make_caracter(c);
    }
    else if(is_integer(c))
    {
        return make_integer(temp_chaine,c);
    }
    else return error;
}
//pour integer faire fonction is int pour voir si il s'agit d'un int ou pas
// prendre en compte les fonctions ou pas


//void print_atom( object * );
object *read_pair( char * )

//void print_pair( object * );
