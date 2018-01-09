/***************************************/
/* Luis Garcia                         */
/* Friday September 8, 2017            */
/* CS 241 Section 1                    */
/* Lab 2                               */
/***************************************/

#include <stdio.h>

#define IN 1 /*Inside a word*/
#define OUT 0 /*Outside a word*/

/***************************************/
/*Main function, no parameters         */
/*Couting Char,Spaces,Word             */
/*from Standar input                   */
/***************************************/
int main(void)
{

  int totalCharacteres;
  int totalPalabras;
  int lineaCharacter;
  int lineaPalabra;
  int numeroLinea;
  int characterPopular;
  int characterPopularLinea;
  int palabraPopular;
  int palabraPopularLinea;
  int c;
  int estado;
  int estadoFalso;
	
  c = 0;
  totalCharacteres= 0;
  totalPalabras=0;
  lineaCharacter = 0;
  lineaPalabra = 0;
  numeroLinea = 0;
  characterPopular = 0;
  characterPopularLinea = 0;
  palabraPopular = 0;
  palabraPopularLinea = 0;
	
  estado = IN;
  estadoFalso = OUT;

	/*printf("necesitamos poner todo en fila, luego contar el numero de
	          charachteres, y luego las palabras");*/

	while((c = getchar()) != EOF)
	{
	  
	  if(estado)
	  {
	      numeroLinea++;
	      printf("%2d. ",numeroLinea);
	      estado = OUT;
	  }
	    
	  
		if(c == '\n')	/*this comes from the Book of the C programming, they explain the back slash*/
	  {
	    
	    printf("(%d,%d)", lineaPalabra, lineaCharacter);
	    estado= IN;
	    
	    totalCharacteres = totalCharacteres + lineaCharacter;
	    totalPalabras = totalPalabras + lineaPalabra;

	    if(lineaCharacter >= characterPopular)
	    {
				characterPopular = lineaCharacter;
				characterPopularLinea = numeroLinea;
	    }

	    if(lineaPalabra >= palabraPopular)
	    {
				palabraPopular = lineaPalabra;
				palabraPopularLinea = numeroLinea;
	    }
	    
	    	lineaCharacter = 0;
	    	lineaPalabra = 0;
	  }
		
	  
	  if( c == ' ' || c == '\t' || c == '\n')    /* si estamos en espacio, tab o nueva linea no estamos en palabra*/
	  {
	  	estadoFalso = OUT;
	  }
	  
	  else if(!estadoFalso)
	  {
	  	estadoFalso= IN;
	   	lineaPalabra++;
	  }
	   
	  printf("%c",c);  /*A hint given by brooke on the pdf of the lab*/
	  if (c != '\n')
	  {
			lineaCharacter++;
	  }
		
	}

	printf("%d lines, %d words, %d characters\n",numeroLinea,totalPalabras,totalCharacteres);
	printf("Line %d has the most words with %d\n",palabraPopularLinea,palabraPopular);
	printf("Line %d has the most characters with %d\n",characterPopularLinea,characterPopular);
	

	return 0;
}
