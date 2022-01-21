#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "FPE.h"

int main(void) {
  FILE *textoUsuario, *textoStopwords, *TextoNuevo, *NoStopWords, *ListaMezclaDirecta;
  struct palabras *Pcabecera, *Pactual, *PcabeceraSW,*PactualSW, *Panterior; //Las "P" son de palabra
  struct palabras* palabraComparar;
  struct palabras* palabraAComparar;
  char direccionArchivo[75], direccionArchivoSW[75]; 
  unsigned char palabras[35], selectorDeMetodo[1];
  int i = 0, longitudPalabraUsuario, longitudStopWord, PalabraUsuarioEncontrada, ContarLineasNSW;

   
  
  system("cls");
  //Interfaz para obtener la dirección del archivo del usuario
  do{
    interfazBienvenida(direccionArchivo);//Esta funci�n se emplea para obtener la direcci�n en donde se encuentra el archivo mediante una interfaz
    textoUsuario = fopen(direccionArchivo, "r");
    disponibleArchivo(textoUsuario, 155);//Función empleada en verificar si se pudo abrir el archivo con exito
  }while(textoUsuario == NULL);
	fflush(stdin);
	
	//Interfaz archivoStopWords
	do{
		interfazArchivoSW(direccionArchivoSW);
		textoStopwords = fopen(direccionArchivoSW, "r");
		disponibleArchivo(textoStopwords, 558984);
	}while(textoStopwords == NULL);
	fclose(textoStopwords);
	fflush(stdin);
  
  //Interfaz para seleccionar que metodo emplear
	selectorDeMetodo[0] = '1';
	
	
	
  do{
	  
	  interfazSelectorOrden();
	  printf("         >");
	  scanf("%s", &selectorDeMetodo);
	  system("cls");
	 
	  fflush(stdin);
	  if(	(selectorDeMetodo[0] < 49	|| 	longitudCadena(selectorDeMetodo)>1) || (selectorDeMetodo[0] > 51	|| longitudCadena(selectorDeMetodo)>1)	){ //Condicional para que el usuario no de entradas incorrectas
		  puts("No ingrese opciones inexistentes");
		  sleep(2);
	  }
  }while(	(selectorDeMetodo[0] < 49	|| 	longitudCadena(selectorDeMetodo)>1 ) || (selectorDeMetodo[0] > 51	|| longitudCadena(selectorDeMetodo)>1)	);

  
  //El siguiente paso a realizar es hacer una lista con las palabras del texto usuario, para eso se abrira el archivo de texto nuevo para escribir con ello.
  
  TextoNuevo = fopen("TextoNuevo.txt","w");
  disponibleArchivo(TextoNuevo,189);
  
  //printf("LONGITUD SELECTOR: %d",longitudCadena(selectorDeMetodo));
  //Proceso para pasar las palabras del texto usuario a texto nuevo.

 /* Esta función servirá para almacenar las palabras del texto del usuario en un 
 nuevo archivo*/
  while(!feof(textoUsuario)){
    
    //Definimos el contador como 0, en cada iteracion para que siempre lea el inicio de la palabra
    i = 0;
    // Busca un espacio y lo guarda en el string palabras
    fscanf(textoUsuario, " %[^' ']", &palabras[0]); 
    
    // Calcula la longitud de la palabra
    int longitudpalabras = longitudCadena(palabras);
    // Asigna un final de linea obligatorio
    palabras[longitudpalabras]= '\0';

    // Comprueba todos los caracteres de la palabra actual con la funcion         comprobacion Sp
    while(palabras[i] !='\0' ){
    comprobacionSp(palabras[i], TextoNuevo);
    // Aumenta una unidad el contador i
    i++;
    }
    
    if(!feof(textoUsuario)){
    fprintf(TextoNuevo, "\n");//Con esto se da un salto de linea entre cada       palabra, para que sea más facil el almacenamiento en listas las palabras.
    }
    
  }
  
  fclose(textoUsuario);//Aqui se cierra el archivo del usuario, debido a que ya extraimos los datos necesarios para ejecutar el programa.

  fclose(TextoNuevo); //Debido a que ya almacenamos las palabras en el archivo texto nuevo, y no tenemos más interes en modificarlo, hasta que ya se hayan acomodados las palabras.

  // -------Proceso para almacenar las palabras del textousuario en una lista dinamica-------

  TextoNuevo = fopen("TextoNuevo.txt", "r"); //abrimos nuevamebte el texto nuevo para lectura
   
  Pcabecera = creacionNodoIncial(TextoNuevo);
  insertarNodo(TextoNuevo, &Pcabecera);
  fclose(TextoNuevo); //Se cierra el texto nuevo debido a que ya obtenimos las palabras que necesitabamos.
  
  // -------Proceso para almacenar las palabras de stop_word.txt en una lista dinamica-------
  textoStopwords = fopen(direccionArchivoSW,"r");
  
  PcabeceraSW = creacionNodoIncial(textoStopwords);
  insertarNodo(textoStopwords, &PcabeceraSW);
  fclose(textoStopwords);

  //--------Proceso para comparar las palabras del textousuario con StopWords
 
  // se define la cabecera para leer todas las palabras del usuario.
   Pactual = Pcabecera;

  while(Pactual != NULL){
    PalabraUsuarioEncontrada = 0;
    longitudPalabraUsuario = longitudCadena(Pactual->palabra);

  // cuando la palabra usuario cambie, se reinicia la lectura de la lista stopwords
    PactualSW = PcabeceraSW;
    while(PactualSW != NULL){
    longitudStopWord = longitudCadena(PactualSW->palabra);
      if(longitudStopWord == longitudPalabraUsuario){
        
        PalabraUsuarioEncontrada = compararCadenas(PactualSW->palabra, Pactual->palabra);
        if(PalabraUsuarioEncontrada == 1){
          
          break;
        }
      }
      PactualSW = PactualSW -> enlace;
    }

    // Condicion para eliminar todas las palabras encontradas en stopwords
    if(PalabraUsuarioEncontrada == 1){
      eliminarElementoLista(&Pcabecera, Pactual->palabra);
    }
    
    Pactual = Pactual -> enlace;
  }




  //--------Proceso para leer de nuevo la lista de palabras que no son StopWords y las almacena en el archivo non_stop_words.txt--------
  NoStopWords = fopen("Non_stop_words.txt", "w");
  puts("");
  
  Pactual = Pcabecera;
  while(Pactual != NULL){
      
      fprintf(NoStopWords, "%s\n" ,Pactual -> palabra);
    Pactual = Pactual -> enlace;
  }

   fclose(NoStopWords);
  
   eliminadorDeListasE(&Pcabecera);



  //--------Proceso para ordenar las palabras que no son StopWords con el metodo burbuja (Alfebetico)--------
  NoStopWords = fopen("Non_stop_words.txt", "r");
  Pcabecera = creacionNodoIncial(NoStopWords);


  
    insertarNodo(NoStopWords, &Pcabecera);//insertamos las palabras en un nodo
    fclose(NoStopWords);
    NoStopWords = fopen("Non_stop_words.txt", "r");
    ContarLineasNSW=contarLineas(NoStopWords);//Sacamos el total de palabras no stopwords
    fclose(NoStopWords);

    NoStopWords = fopen("auxiliarNSW2.txt", "w");
   
//Proceso que guarda las palabras que no son stopwords en un texto auxiliar
  Pactual = Pcabecera;
  Panterior = NULL;
  while (Pactual != NULL){

	if(Pactual ->enlace != NULL){
    fprintf(NoStopWords,"%s\n",Pactual -> palabra);
  } 

   
    // fputs("\n", NoStopWords);
    Panterior = Pactual;
    
		Pactual = Pactual -> enlace;
    
    
    
	}
  fclose(NoStopWords);//Acá cerramos el texto auxiliar
  
  //printf("Cabecera %s\n", Pcabecera->palabra);
  //Ciclo que ordena las palabras en base a la selección del usuario
  if(selectorDeMetodo[0] == '1'){
	  
   metodoBurbuja(&Pcabecera, ContarLineasNSW);


  }else if(selectorDeMetodo[0] == '2'){
   metodoQuickSort(&Pcabecera);
    
  }else if(selectorDeMetodo[0] == '3'){
    //Para el método externo, todo se debe realizar a través de archivos, nada de listas enlazadas.
    mezclaDirecto();
    //Borramos los datos de Pcabecera para almacenar las palabras (Ordenadas)
    free(Pcabecera);
    //Leemos el archivo ListaUnion
    ListaMezclaDirecta = fopen("ListaUnion.txt", "r"); //abrimos nuevamebte el texto nuevo para lectura
   
    // Creamos su nodo inicial e insertamos las palabras
    Pcabecera = creacionNodoIncial(ListaMezclaDirecta);
    insertarNodo(ListaMezclaDirecta, &Pcabecera);
    //Cerramos el archivo
    fclose(ListaMezclaDirecta);

  }





  
  //-------Proceso para obtener la longitud de las palabras-------
  Pactual = Pcabecera;
  while(Pactual != NULL){
		Pactual -> longitud = longitudCadena(Pactual -> palabra);
		Pactual = Pactual -> enlace;
  }
  
  //-------Proceso para eliminar palabras repetidas-------
  palabraComparar = Pcabecera;
  palabraAComparar = Pcabecera -> enlace;
  int indicePalabra;
  while(palabraAComparar != NULL){
    indicePalabra = palabraComparar->indice;
	  //Condicion que comprueba si algun caracter de la palabra es igual a algun otro caracter de la palabra a comparar, en caso de que esto se cumpla, se efectua un proceso para que solo salga 1 vez la palabra
	  if(palabraComparar -> longitud == palabraAComparar -> longitud){ 
		  for(i = 0; i < palabraComparar -> longitud; i++){
			  if(palabraComparar -> palabra[i] != palabraAComparar -> palabra[i]){
				  palabraComparar = palabraComparar -> enlace;
				  palabraAComparar = palabraComparar -> enlace;
				  break;
			  }
        
			  
		  }
      indicePalabra++;
		  //condición que comprueba si se lleg� al final en ambas palabras sin ninguna coincidencia, de no ser el caso se sustituye una con la otra para que solo quede una palabra 
		  if(palabraComparar -> palabra[i] == '\0' && palabraAComparar ->   palabra[i] == '\0'){
        palabraComparar -> enlace = palabraAComparar -> enlace;
			  palabraComparar -> indice = indicePalabra;
			  free(palabraAComparar); //liberamos palabraAComparar de la memoria para optimizar el programa
			  palabraAComparar = palabraComparar -> enlace;
		  }
	  }else{
			palabraComparar = palabraComparar -> enlace;
			palabraAComparar = palabraComparar -> enlace;
	  }
    
    
  }
 
  NoStopWords = fopen("Non_stop_words.txt", "w");
	
  Pactual = Pcabecera ;
  //Panterior = Pcabecera;
  //free(Panterior);
  //proceso que escribe las palabras sin stopwors y ordenadas en el documentto non_Stop_words
  while (Pactual != NULL){
    //printf( "%s - %d\n",Pactual -> palabra, Pactual -> indice);
    fprintf(NoStopWords, "%s - %d\n", Pactual -> palabra,Pactual -> indice);
	  Pactual = Pactual -> enlace;
  }
  fclose(NoStopWords);
  
  remove("auxiliarNSW2.txt");
 
  remove("ListaDos.txt");
  
  remove("ListaUno.txt");
 
  remove("ListaUnion.txt");
  
  remove("TextoNuevo.txt");
  
  interfazDespedida(selectorDeMetodo[0]);
  

  return 0;
}
