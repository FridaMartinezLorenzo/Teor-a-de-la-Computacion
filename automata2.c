/*********************************************************************************************
Funcionalidad: El programa que acepta como validas aquellas palabras que son aceptadas por el autómata. 
			   Esimportante considerar las transiciones λ.

Asignatura: Teoría de la computación
Profesor: M.C Verónica Rodríguez López
Alumno: Frida Ximena Martínez Lorenzo
Grupo: 302-B

**********************************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Prototipados

void q0(char *, int);
void q1(char *, int);
void q2(char *, int);
void q3(char *, int);
void q5(char *, int);
void q6(char *, int); //Representará al estado basura

int main (){
	printf("Es importante marcar un espacio al final para que sea tomado como la cadena vacia (λ)")
	printf("Ingrese la palabra: ");
	fflush(stdin);
	char *p = (char*)malloc (sizeof(char));
	gets(p);
	int l=strlen(p);
	int i=0;
	q0(p,i);
	return 0;
}


char identificador (char dato){
	if (isspace (dato))
		return 'a'; //Significa que es es λ.
	if (isdigit (dato))
		return 'b'; //Significa que es un número
	switch (dato){
		case '+': return 'c'; //Significa que es +
				  break;
		case '-': return 'd'; //Significa que es -
				  break;
		case '.': return 'e'; //Significa que es un punto
				  break;
		default: return 'f'; //Significa que es cualquier otra tecla
	}
}

//________________________________________________________
void q0 (char *p, int i){
	char dato, val;
	dato = p[i];
	i++;
	val = identificador (dato);
	switch (val){
		case 'a': q1(p,i);
				  break;
		case 'b': q1(p,i);
			   	  break;
		case 'c': q1(p,i);
				  break;
		default: q6(p,i);//q0
	}
}
//_________________________________________________________________
void q1 (char *p, int i){
	char dato, val;
	dato = p[i];
	i++;
	val = identificador (dato);
	switch (val){
		case 'b': q1(p,i);
				  break;
		case 'e': q2(p,i);
			   	  break;
		default: q6(p,i);
	}
}
//_________________________________________________________________
void q2 (char *p, int i){
	char dato, val;
	dato = p[i];
	i++;
	val = identificador (dato);
	switch (val){
		case 'b': q3(p,i);
				  break;
		default: q6(p,i);	
	}
}
//_________________________________________________________________
void q3 (char *p, int i){
	char dato, val;
	dato = p[i];
	i++;
	val = identificador (dato);
	switch (val){
		case 'a': q5(p,i);
				  break;
		case 'b': q3(p,i);
			   	  break;
		default: q6(p,i);
	}
}
//_________________________________________________________________
void q5 (char *p, int i){ //Estado final
 	printf("Esta es una palabra valida");
}
//__________________________________________________________________
void q6 (char *p, int i){
	printf("No es una palabra valida");
	free(p);//La palabra es deshechada de forma automática
	exit(1);
} 

