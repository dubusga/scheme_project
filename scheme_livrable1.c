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
object* make_symbol(char sym,char* chaine)
{
	object symbole;
	char new_carac;
	symbole.type=1;
	symbole=sym;
	new_carac=get_next_char(&chaine);
	while(is_caractere(new_carac))
	{
		symbole=strcat(symbole,&new_carac);
		new_carac=get_next_char(&chaine);
	}
	return &sym;
}

object *make_caractere( char  carac,char* chaine)// a revoir car peut etre chaine de caractere
{
	object caractere;
	char new_carac;
	caractere.type=4;
	caractere="#\";
	caractere=strcat(caractere,&carac);
	new_carac=get_next_char(&chaine);
	while(is_symbol(new_carac))
	{
		caractere=strcat(caractere,&new_carac);
		new_carac=get_next_char(&chaine);
	}
	return &caractere;
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
int is_symbol(char sym)
{
    if(sym>=0x3F  && sym<=0x7A || sym>=0x24 && sym<=0x2D || sym==0x21 ||sym==0x22)
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
            return make_caractere(c, temp_chaine);} //attention if symbol ou character
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
    if(is_symbol(c))
    {
        return make_symbol(c);
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
