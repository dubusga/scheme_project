#include<stdio.h>
#include"object.h"


/// Fonction retournant 0,1,2,3 respectivement si ce qui est passé en paramètre est non défini, un atome, un liste, une empty_list
int test_atom_pair_empty(object* obj){
  if (((obj->type=>0)&&(obj->type=<2))||((obj->type=<8)&&(obj->type=>5))){
    return 1;
  }
  else {
    if((obj->type==3) {
	return 2;
      }
      else{
	if(obj->type==4){
	  return 3;
	}
	else 
	  {
	    printf(stderr, "Erreur: L'object* n'a pas de type défini!!");
	    ///Faire arreter le programme !!
	  }
      }
      }
  }

///Fonction prenant un object* en parametre pour retourner le type et la valeur d'un atome
///Elle vérifie que c'est bien un atome PUIS trouve son type PUIS renvoie sa valeur et son type
void print_atom(object obj){
  char type;
  if (test_atom_pair_empty==1){
    switch (obj->type){
    case '6':
      type="symbol";
      break;
    case '5':
      type="boolean";
      break;
    case '0':
      type="integer";
      break;
    case '1':
      type="character";
      break;
    case '2':
      type="string";
      break;
    case '8':
      type="primitive";
      break;
    }
    fprintf(stdout, %d ,type);
    fprintf(stdout, %s ,obj->data);
  }
  else
    {
      if (test_atom_pair_empty==2){
	printf(stderr, "Erreur: La fonction ne traite pas les paires ! Il faut lui donner un atome !!!");
      }
      else {
	printf(stderr, "Erreur: L'object* n'a pas de type défini !!");
      }
      ///Arreter le programme 
    }
}

///Fonction affichant une paire
void sfs_print_pair(object paire){
     print(paire->car);
     print(paire->cdr);
}

///Fonction print globale !
 void sfs_print(object obj){
   if (test_atom_pair_empty==2){
     if (test_atom_pair_empty(obj->car)==2){
       fprintf(stdout, '(');
     }  
     print_pair(obj);
     if (test_atom_pair_empty(obj->car)==2){
       fprintf(stdout, ")");

     }
   }
  else {
    if (test_atom_pair_empty==1){
      print_atom(obj);
      if (obj->cdr =! "()"){
	fprintf(stdout, ' ');
      }
    }
    else {
      if (test_atom_pair_empty==3){
	fprintf(stdout,);
      }
      else {
      fprintf(stderr,"Erreur: l'object* n'est ni une liste ni un atome" );
      }
    }
  }
}


    
