#define N 2

struct palabras{
	unsigned char palabra[35];
	int indice;
  int longitud;
	struct palabras *enlace;
};




void interfazBienvenida(char direccion[]){
	printf("__________________________________________________________\n");
	printf("                                                          \n");
	printf(" Proyecto final: Lectura de palabras stopwords, separación \n");
	printf("                      y ordenamiento                      \n");
	printf("__________________________________________________________\n");                       
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("  ||Ingrese la dirección del documento con su nombre||\n");
	printf("\n");
	printf("         En caso de que el programa se encuentre\n");
	printf("         En la misma carpeta que el archivo\n");
	printf("         De texto solo ponga el nombre\n");
	printf("\n");
	printf("          >");
	//scanf("%s", "textoUsuario.txt");
	scanf("%s", direccion);
	system("cls");
}

void interfazSelectorOrden(void){
	unsigned char NumeroOrden[1];
	system("cls");
	printf("__________________________________________________________\n");
	printf("                                                          \n");
	printf(" Proyecto final: Lectura de palabras stopwors, separación \n");
	printf("                      y ordenamiento                      \n");
	printf("__________________________________________________________\n");   
	printf("\n");
	printf("         Ingrese el número del método ordenamiento\n");
	printf("            - Internos\n");
	printf("               1. Burbuja\n");
	printf("               2. Quicksort\n");
	printf("            - Externos \n");
	printf("               3. Método Directo \n");
	printf("              \n");

}

void interfazDespedida(int selectorInterfaz){
  if(selectorInterfaz == '1'){
    printf("__________________________________________________________\n");
	  printf("                                                          \n");
	  printf(" Proyecto final: Lectura de palabras stopwors, separación \n");
  	printf("                      y ordenamiento                      \n");
	  printf("__________________________________________________________\n");                  
  	printf("|                                                        |\n");
  	printf("|                                                        |\n");
  	printf("|                                                        |\n");
  	printf("|        Se ha creado un archivo con el nombre           |\n");
  	printf("|        Non_stop_words.txt sin las stopwords y          |\n");
	  printf("|        ordenado con el método burbuja                  |\n");
	  printf("|                                                        |\n");
	  printf("|                                                        |\n");
	  printf("|                                                        |\n");
	  printf("__________________________________________________________\n"); 
  
	  sleep(2);
  }else if(selectorInterfaz == '2'){
    printf("__________________________________________________________\n");
	  printf("                                                          \n");
	  printf(" Proyecto final: Lectura de palabras stopwors, separación \n");
  	printf("                      y ordenamiento                      \n");
	  printf("__________________________________________________________\n");                  
  	printf("|                                                        |\n");
  	printf("|                                                        |\n");
  	printf("|                                                        |\n");
  	printf("|        Se ha creado un archivo con el nombre           |\n");
  	printf("|        Non_stop_words.txt sin las stopwords y          |\n");
	  printf("|        ordenado con el método Quicksort                |\n");
	  printf("|                                                        |\n");
	  printf("|                                                        |\n");
	  printf("|                                                        |\n");
	  printf("__________________________________________________________\n"); 
  
	  sleep(2);
  }else if(selectorInterfaz == '3'){
	  printf("__________________________________________________________\n");
  	printf("                                                          \n");
	  printf(" Proyecto final: Lectura de palabras stopwors, separación \n");
  	printf("                      y ordenamiento                      \n");
  	printf("__________________________________________________________\n");                  
  	printf("|                                                        |\n");
	  printf("|                                                        |\n");
	  printf("|                                                        |\n");
	  printf("|        Se ha creado un archivo con el nombre           |\n");
  	printf("|        Non_stop_words.txt sin las stopwords y          |\n");
  	printf("|        ordenado con el método de mezcla directa        |\n");
  	printf("|                                                        |\n");
  	printf("|                                                        |\n");
	  printf("|                                                        |\n");
	  printf("__________________________________________________________\n"); 
  
	  sleep(2);
  }
}

  
  
  
void interfazArchivoSW(char direccion[]){
	printf("__________________________________________________________\n");
	printf("                                                          \n");
	printf(" Proyecto final: Lectura de palabras stopwords, separación \n");
	printf("                      y ordenamiento                      \n");
	printf("__________________________________________________________\n");                       
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("  ||Ingrese la dirección del documento de stopwords con su nombre||\n");
	printf("\n");
	printf("         En caso de que el programa se encuentre\n");
	printf("         En la misma carpeta que el archivo\n");
	printf("         De texto solo ponga el nombre\n");
	printf("\n");
	printf("          >");
	//scanf("%s", "textoUsuario.txt");
	gets(direccion);
	system("cls");
	sleep(2);
}

void disponibleArchivo (FILE *f, int e){
 if(f == NULL){
    printf("No se ha podido abrir el archivo ERROR: %d", e);
    puts("");
    sleep(3);
    system("cls");
  }else{
    puts("           | Se archivo abrió con exito |  ");
    puts("");
    sleep(1);
    system("cls");
  }
}

int longitudCadena(unsigned char cad[]){
      int i = 0;
    while (cad[i] != '\0')
        i++;
    return i;
}

int encontrarCadena(unsigned char cad1[], unsigned char cad2[]){
    int i, j, encontrada = 0, longitud;
    j = 0;
    longitud = longitudCadena(cad2);
    for(i=0; i<longitud;i++ ){
        // printf("cad2: %c , cad1: %c\n",cad2[i],cad1[i]);
        if(cad2[i] == cad1[j]){
            encontrada = 1;
            j++;
        }else{
            j=0;
            encontrada = 0;
        }
        if(cad1[j] == '\0'){
                return encontrada;
        }
    }
    return encontrada;
}


int contarLineas(FILE *puntero){
  char ca;
  int cont = 1;
  while(1){

        ca = fgetc(puntero);

        if(ca == '\n'){
            cont++;
            //printf("%d\n",cont);
        }
        if(ca == EOF){  //Si el caracter es end of file imprimimos el contador y salimos del while
            return cont; //El nï¿½mero de lineas
            break;
        }
    }
}

int fContarLineas(FILE *puntero){
  char ca;
  int cont = 1;
  while(1){

        ca = fgetc(puntero);

        if(ca == '\n'){
            cont++;
            //printf("%d\n",cont);
        }
        if(ca == EOF){  //Si el caracter es end of file imprimimos el contador y salimos del while
            return cont; //El nÃºmero de lineas
            break;
        }
    }

}

int longitudNombres(unsigned char cad[]){
      int i = 0;
    while (cad[i] != '\n')
        i++;
    return i;
}
//ComprobaciÃ³n de signos de puntuaciÃ³n, esta funciÃ³n se emplea para comparar cada         caracter y asi determinar si es un signo de puntuaciÃ³n y asÃ­ no escribirlo.
void comprobacionSp(unsigned char caracter, FILE *archivoDondeImprimir){
  if(caracter != '.' && caracter != ',' && caracter != ':' && caracter != ';' && caracter != '.' && caracter != '?' && caracter != '!' && caracter != '.' && caracter != '[' && caracter != ']' && caracter != '(' && caracter != ')' && caracter != '"' ){
      fprintf(archivoDondeImprimir, "%c", tolower(caracter));
      }
}


struct palabras* creacionNodoIncial(FILE* archivoPalabras){
	struct palabras* Pcabecera;
	Pcabecera = (struct palabras*)malloc(sizeof(struct palabras));
	fscanf(archivoPalabras, " %[^'\n']", &Pcabecera -> palabra[0]);
	Pcabecera -> indice = 1;
	Pcabecera -> enlace = NULL;
	return Pcabecera;
}

void insertarNodo(FILE* archivoPalabras, struct palabras **Pcabecera){
	struct palabras  *Pactual, *Panterior, *Pnueva;
	while(!feof(archivoPalabras)){ //Mientras no se haya llegado al fin del archivo que se lean las palabras
		Pnueva = (struct palabras*)malloc(sizeof(struct palabras));
		Pactual = *Pcabecera;
		Panterior = NULL;
		while(Pactual != NULL){
			Panterior = Pactual;
			Pactual = Pactual -> enlace;
		}
    if(!feof(archivoPalabras)){
      fscanf(archivoPalabras, " %[^'\n']", Pnueva -> palabra);
	  
	  if(longitudCadena(Pnueva -> palabra) > 0){
		  Pnueva -> indice = 1;
		  Pnueva -> enlace = NULL;
		  Panterior -> enlace = Pnueva;
	  }
		  
    }
	}
}


int compararCadenas(unsigned char cad1[],unsigned char cad2[]){
    int i;
    int iguales = 0;

    //Proceso para usar la longitud de cadena mas grande
    int longitud1 = longitudCadena(cad1);
    int longitud2 = longitudCadena(cad2);
    int longitud;
    if(longitud1 > longitud2){
        longitud = longitud1;
    }else{
        longitud = longitud2;
    }
    for(i=0; i<longitud;i++){
        if(cad1[i] == cad2[i]){
            iguales = 1;
        }else{
            iguales = 0;
            return iguales;
        }
    }
    return iguales;
    
}

void eliminarElementoLista( struct palabras** Pcabecera, unsigned char palabraBorrar[]){
	struct palabras* Pactual; 
	struct palabras* Panterior;//Se declara la variable puntero actual
	Pactual = *Pcabecera;
	Panterior = NULL;
	
	while (Pactual !=NULL){
		
		if(Pactual -> palabra == palabraBorrar &&Panterior != NULL){
			Panterior-> enlace = Pactual-> enlace;
			return; 
		}else if(Pactual -> palabra == palabraBorrar && Panterior == NULL){
			
			*Pcabecera = Pactual->enlace;
			return;
		}
		Panterior = Pactual;
		Pactual = Panterior->enlace;
		
	}
	
	
	return;
}



void eliminadorDeListasE(struct palabras** lista){
  struct palabras* Pactual; 
	struct palabras* Panterior;//Se declara la variable puntero actual
	Pactual = *lista;
	Panterior = NULL;

  while(Pactual != NULL){
    Panterior = Pactual;
    Pactual = Pactual -> enlace;
    free(Panterior);
  }
  
}

  
  
void metodoBurbuja(struct palabras** Pcabecera, int totalLineasArchivoNSW){
	int l = 0;
	char auxiliar[35];
	for(l = 0; l < totalLineasArchivoNSW; l++){
		int i = 0, j = 0, k = 0; 
    struct palabras* anterior;
		struct palabras* palabraComparar;
		struct palabras* palabraAComparar;
		
		palabraComparar = *Pcabecera;
		palabraAComparar = *Pcabecera;
		while(palabraComparar -> enlace != NULL){
			
			if(palabraAComparar -> enlace != NULL){
        anterior = palabraAComparar;
				palabraAComparar = palabraAComparar -> enlace;
			}

      

			//proceso que comprueba si la primera letra de la variable palabraComparar es mayor a la primera letra de la variable palabraAComparar
			if(palabraComparar -> palabra[0] > palabraAComparar -> palabra[0]){ 
				
				for(i = 0; i < 35; i++){
					
					auxiliar[i] = palabraComparar -> palabra[i];
					palabraComparar -> palabra[i] = palabraAComparar -> palabra[i];
					palabraAComparar -> palabra[i] = auxiliar[i];
				}
			}else if(palabraComparar -> palabra[0] == palabraAComparar -> palabra[0]){ //proceso que verifica que la primera letra de la variable palabraComparar es igual a la primera letra de la variable palabraAComparar
				for(i = 1; i < 35; i++){
					if(palabraComparar -> palabra[i] > palabraAComparar -> palabra[i]){
						for(j = 0; j < 35; j++){
							auxiliar[j] = palabraComparar -> palabra[j];
							palabraComparar -> palabra[j] = palabraAComparar -> palabra[j];
							palabraAComparar -> palabra[j] = auxiliar[j];
						}
						break;
					}else if(palabraAComparar -> palabra[i] > palabraComparar -> palabra[i]){ //Proceso que verifica si la primera letra de PalabraAComparar es mayor que la primera letra de palabraComparar
						break;
					}
				}
			}
			
			palabraComparar = palabraComparar -> enlace;
			
			k++; //Porfavor de no eliminar esta k++ si no el programa por alguna razï¿½n ya no funciona [Horas invertidas tratando de averiguar el porque: 6 hrs]
		}
		
		
		
	}
	
	
}  

struct palabras* crearNodoCabecera(unsigned char palabra[]){
	int i;
	struct palabras* nuevo; //Se declara la variable puntero
  int longitudPalabra = longitudCadena(palabra);
	nuevo = (struct palabras*)malloc(sizeof(struct palabras)); // Se reserva la memoria para el nuevo nodo

	for(i= 0;i<longitudPalabra;i++){
		nuevo -> palabra[i]= palabra[i]; 
	}
	nuevo->palabra[i] = '\0';//Se asigna valor al miembro dato del nodo
  nuevo->longitud = longitudPalabra;
  nuevo->indice = 1;
	nuevo -> enlace = NULL; //Se asigna NULL al miembro enlace del nodo
	return nuevo;
}


void insertarNodoQuick(unsigned char palabra[35], struct palabras** puntero){
	int i;
	struct palabras* actual; //Se declara la variable puntero actual
	struct palabras* anterior; //Se declara la variable puntero anterior
	actual = *puntero;
	anterior = NULL;
  int longitudPalabra = longitudCadena(palabra);
		
	while (actual != NULL){
		anterior =  actual;
		actual = anterior-> enlace;
	}
	
	struct palabras* nuevo;
	nuevo = (struct palabras*)malloc(sizeof(struct palabras)); // Se reserva la memoria para el //nuevo nodo
  if(longitudPalabra <1){
    return;
  }
	for(i=0 ; i<longitudPalabra;i++){
		nuevo->palabra[i] = palabra[i];
	}
  nuevo->longitud = longitudPalabra;
	nuevo->palabra[i] = '\0';
	nuevo->enlace = NULL;
  nuevo->indice = 1;
	anterior->enlace = nuevo;
	return;
}

struct palabras* ContatenarListasQuick(struct palabras* Listaizquierda, struct palabras* Pivote, struct palabras* ListaDerecha){
	
	struct palabras* Pactual;

	struct palabras* ListaConcatenada; //Se declara la variable puntero
	ListaConcatenada = (struct palabras*)malloc(sizeof(struct palabras)); // Se reserva la memoria para el nuevo nodo
	
	// Recorremos la lista izquierda y agregamos todos los elementos a lista concatenada
	Pactual = Listaizquierda;
	while(Pactual != NULL){
		if(Pactual == Listaizquierda){
			ListaConcatenada = crearNodoCabecera(Pactual->palabra);
		}else{
      insertarNodoQuick(Pactual->palabra, &ListaConcatenada);
    }
		
		Pactual = Pactual ->enlace;
	}

	// Cuando termine el ciclo de la lista izquierda agregamos el pivote
	insertarNodoQuick(Pivote->palabra, &ListaConcatenada);
	// ListaConcatenada = Pivote;
	// ListaConcatenada->enlace = NULL;

	// Despues recorremos la lista derecha y agregamos todos los elementos a listaConcatenada
		Pactual = ListaDerecha;
	while(Pactual != NULL){
		insertarNodoQuick(Pactual->palabra, &ListaConcatenada);
		Pactual = Pactual ->enlace;
	}

	return ListaConcatenada;
}

void  metodoQuickSort(struct palabras** Pcabecera){
	int  j = 0;
	
	struct palabras * Pivote;
	struct palabras * Pactual;
	struct palabras * Panterior;
  struct palabras * Pcomparar;
	struct palabras * listaIzquierdaCabecera = NULL;
	struct palabras * listaDerechaCabecera = NULL;


 
  


  

 //Planteamos el caso base de la recursividad, cuando solo haya 1 elemento en cada lista
 Pivote = *Pcabecera;
 if(Pivote == NULL || Pivote -> enlace == NULL){
  return;
 }
 
	Pcomparar = Pivote -> enlace;
	Panterior = NULL;


int longitudPalabra;

	while(Pcomparar != NULL){
    longitudPalabra = longitudCadena(Pcomparar->palabra);
    // Solo compara las palabras que no estan vacias
    if(longitudPalabra >=1){
		if(Pcomparar -> palabra[0] > Pivote-> palabra[0]){ 
				//printf("Comparando %s con %s \n ", Pcomparar->palabra, Pivote->palabra);
				if(listaDerechaCabecera == NULL){
					listaDerechaCabecera = crearNodoCabecera(Pcomparar->palabra);
				}else{
					insertarNodoQuick(Pcomparar->palabra, &listaDerechaCabecera);
				}
			}else if(Pcomparar -> palabra[0] < Pivote-> palabra[0]){
				if(listaIzquierdaCabecera == NULL){
					listaIzquierdaCabecera =  crearNodoCabecera(Pcomparar->palabra);
				}else{
					insertarNodoQuick(Pcomparar->palabra, &listaIzquierdaCabecera);
				}
			}else if(Pcomparar -> palabra[0] == Pivote-> palabra[0]){
        for(j = 1; j < 35; j++){
          if(Pcomparar -> palabra[j] > Pivote -> palabra[j]){
            if(listaDerechaCabecera == NULL){
					   listaDerechaCabecera =  crearNodoCabecera(Pcomparar->palabra);
              break;
				    }else{
				  	  insertarNodoQuick(Pcomparar->palabra, &listaDerechaCabecera);
              break;
				    }
          }else if(Pcomparar -> palabra[j] < Pivote-> palabra[j]){
				    if(listaIzquierdaCabecera == NULL){
					    listaIzquierdaCabecera =  crearNodoCabecera(Pcomparar->palabra);
              break;
				    }else{
				    	insertarNodoQuick(Pcomparar->palabra, &listaIzquierdaCabecera);
              break;
			    	}
		    	}else if(Pcomparar -> palabra[j] == '\0' && Pivote -> palabra[j] == '\0'){
            if(listaIzquierdaCabecera == NULL){
					listaIzquierdaCabecera =  crearNodoCabecera(Pcomparar->palabra);
          break;
				}else{
					insertarNodoQuick(Pcomparar->palabra, &listaIzquierdaCabecera);
          break;
				}
          }
        }
			}
		
    }
	
		Panterior = Pcomparar;
		Pcomparar = Pcomparar ->enlace;
	}

	
	
  // Aplica la recursividad para las 2 listas izquierda y derecha
     metodoQuickSort(&listaDerechaCabecera);
     metodoQuickSort(&listaIzquierdaCabecera);
  

  // Concatena la listaIzquierda + Pivote + listaDerecha
	 *Pcabecera = ContatenarListasQuick(listaIzquierdaCabecera, Pivote, listaDerechaCabecera);
	
 
	
}  

int elevarPotencia(int numeroBase, int potencia){
		int valorPotencia = 1;
		for(int i = 0; i < potencia; i++){
			valorPotencia *= numeroBase;
		}
		return valorPotencia;
	}

void mezclaDirecto(){
  int i, j, TotalPalabras;
  FILE *ListaUno, *ListaDos, *ListaUnion, *textoAuxiliar;
  int  k;
  unsigned char Aux1[35], Aux2[35], palabraInsertar[35]; 
  int division, contador = 1;
  int palabracontador;
 int f,g;
 
// Declaramos division como 1, porque en la primera iteracion la lista se divide en palabras de 1 en 1
	division = 1;


    ListaUno = fopen("ListaUno.txt", "w");
	ListaDos = fopen("ListaDos.txt", "w");
	textoAuxiliar = fopen("auxiliarNSW2.txt", "r");
    TotalPalabras = contarLineas(textoAuxiliar);
    fclose(textoAuxiliar);
    textoAuxiliar = fopen("auxiliarNSW2.txt", "r");
    
      while(division < TotalPalabras-1){
		palabracontador =  0;

        if(contador > 1){
			textoAuxiliar = fopen("ListaUnion.txt", "r");
        	ListaUno = fopen("ListaUno.txt", "w");
	    	ListaDos = fopen("ListaDos.txt", "w");
        }

	// ===========PROCESO que divide la lista en dos archivos====================
		while(!feof(textoAuxiliar)){
        k = 0;
		while(k<division &&!feof(textoAuxiliar) ){
			palabraInsertar[0] = '\0';
			fscanf(textoAuxiliar, " %[^'\n']", &palabraInsertar[0]); 
			// palabracontador++;

			// if(longitudCadena(palabraInsertar)>0 &&palabracontador <TotalPalabras-2){
				fprintf(ListaUno, "%s\n", palabraInsertar);
			// }else if(longitudCadena(palabraInsertar)>0 &&palabracontador == TotalPalabras-2){
			// 	fprintf(ListaUno, "%s", palabraInsertar);
			// }


			k++;
			
		 }
		i = 0;
		while(i<division &&!feof(textoAuxiliar)  ){
			palabraInsertar[0] = '\0';
			fscanf(textoAuxiliar, " %[^'\n']", &palabraInsertar[0]); 
			// palabracontador++;
			// if(longitudCadena(palabraInsertar)>0 &&palabracontador <TotalPalabras-1){
				fprintf(ListaDos, "%s\n", palabraInsertar);
			// }else if(longitudCadena(palabraInsertar)>0 &&palabracontador == TotalPalabras-1){
			// 	fprintf(ListaDos, "%s", palabraInsertar);
			// }
			i++;
		 }
        }
		// printf("CONTADOR XD%d\n",palabracontador);
	 
	
    // Cerramos los archivos para evitar errores en los siguientes procesos
    fclose(textoAuxiliar);
    fclose(ListaUno);
    fclose(ListaDos);
	// =======================================================================



    // Inicializamos de nuevo para leer las palabras de listaUno y ListaDos
    ListaDos = fopen("ListaDos.txt", "r");
    ListaUno = fopen("ListaUno.txt", "r");
    ListaUnion = fopen("ListaUnion.txt","w");

	int B1, B2;

	B1 = 1;
	B2 = 1;
	Aux1[0] = '\0';
    Aux2[0] = '\0';

	if(!feof(ListaUno)){
		fscanf(ListaUno, " %[^'\n']", &Aux1[0]);
		B1 = 0;
		
		
	}
	if(!feof(ListaDos)){
		fscanf(ListaDos, " %[^'\n']", &Aux2[0]);
		B2 = 0;
		
	}
	
	
    // Proceso para recorrer los dos archivos y guardar las palabras de cada uno en variables auxiliares
    while((!feof(ListaUno) || B1 == 0)  && (!feof(ListaDos) || B2 == 0)){

      //Reseteamos los valores de Aux1 y Aux2 para que no almacenen valores viejos
    //   Aux1[0] = '\0';
    //   Aux2[0] = '\0';
      // Proceso para almacenar las palabras en variables auxiliares
    //   fscanf(ListaUno, " %[^'\n']", &Aux1[0]);
    //   fscanf(ListaDos, " %[^'\n']", &Aux2[0]);

      
    //   longitudAux1 = longitudCadena(Aux1);
    //   longitudAux2 = longitudCadena(Aux2);


      //#####################Proceso para comparar y fusionar las palabras############################
    f= 0;
	g= 0;
	
	  while((g<division && B1 == 0) && (f<division && B2 == 0)){
		
		if(Aux1[0] < Aux2[0]){
			fprintf(ListaUnion,"%s\n", Aux1);
			B1 = 1;
			g++;
			if(!feof(ListaUno)){
				Aux1[0] = '\0';
				fscanf(ListaUno, " %[^'\n']", &Aux1[0]);
				B1 = 0;
			}
			
		}else if(Aux1[0] > Aux2[0]){
			fprintf(ListaUnion,"%s\n", Aux2);
			B2 = 1;
			f++;
			if(!feof(ListaDos)){
				Aux2[0] = '\0';
				fscanf(ListaDos, " %[^'\n']", &Aux2[0]);
				B2 = 0;
			}
			
		}else if(Aux1[0] == Aux2[0]){

			for(j = 1; j < 35; j++){
				if(Aux1[j] < Aux2[j]){
					fprintf(ListaUnion,"%s\n", Aux1);
					B1 = 1;
					g++;
					if(!feof(ListaUno)){
						Aux1[0] = '\0';
						fscanf(ListaUno, " %[^'\n']", &Aux1[0]);
						B1 = 0;
					}
					break;
				}else if(Aux1[j] > Aux2[j]){
					fprintf(ListaUnion,"%s\n", Aux2);
					B2 = 1;
					f++;
					if(!feof(ListaDos)){
						Aux2[0] = '\0';
						fscanf(ListaDos, " %[^'\n']", &Aux2[0]);
						B2 = 0;
					}
					break;
				}else if(Aux1[j] == '\0' && Aux1[j] == '\0'){
					fprintf(ListaUnion, "%s\n", Aux1);
					fprintf(ListaUnion, "%s\n", Aux2);
					B1 = 1;
					g++;
					B2 = 1;
					f++;
					if(!feof(ListaUno)){
						Aux1[0] = '\0';
						fscanf(ListaUno, " %[^'\n']", &Aux1[0]);
						B1 = 0;
					}
					
					if(!feof(ListaDos)){
						Aux2[0] = '\0';
						fscanf(ListaDos, " %[^'\n']", &Aux2[0]);
						B2 = 0;
					}
					break;
				}
          }

		  	

		}
	}

		if(g<division){
			while(g<division && B1 == 0){
				fprintf(ListaUnion,"%s\n", Aux1);
				B1 = 1;
				g++;
				if(!feof(ListaUno)){
					Aux1[0] = '\0';
					fscanf(ListaUno, " %[^'\n']", &Aux1[0]);
					B1 = 0;
				}
			}
		}
		if(f<division){
			while(f<division && B2 == 0){
				fprintf(ListaUnion,"%s\n", Aux2);
				B2 = 1;
				f++;
				if(!feof(ListaDos)){
					Aux2[0] = '\0';
					fscanf(ListaDos, " %[^'\n']", &Aux2[0]);
					B2 = 0;
				}
			}
		}

	}

	// printf("g tiene valor> %d y division %d \n", g, division);
	// printf("f tiene valor> %d y division %d \n", f, division);
	// printf("B1 %d \nB2 %d \n", B1, B2);

		// if(B1 == 0){
		// 	fprintf(ListaUnion,"%s\n", Aux1);
		// }
		// if(B2 == 0){
		// 	fprintf(ListaUnion,"%s\n", Aux2);
		// }

		// while(!feof(ListaUno)){
		// 	Aux1[0] = '\0';
		// 	fscanf(ListaUno, " %[^'\n']", &Aux1[0]);
		// 	fprintf(ListaUnion,"%s\n", Aux1);
		// }

		// while(!feof(ListaDos)){
		// 	Aux2[0] = '\0';
		// 	fscanf(ListaDos, " %[^'\n']", &Aux2[0]);
		// 	fprintf(ListaUnion,"%s\n", Aux2);
		// }

		 // printf("%s(%d)  -  %s(%d) \n", Aux1, longitudAux1, Aux2, longitudAux2);
		  
	  
	  //puts("-----------------------------------------------------------------------");

	  
    
    //   if(Aux1[0] < Aux2[0]){
    //  if(longitudAux1>0){
    //     fprintf(ListaUnion, "%s\n", Aux1);
        
    //   }
    //   if(longitudAux2>0){
    //     fprintf(ListaUnion, "%s\n", Aux2);
    //   }
        
    //   }else if(Aux1[0] > Aux2[0]){
    //     if(longitudAux2>0){
    //     fprintf(ListaUnion, "%s\n", Aux2);
        
    //     }
    //     if(longitudAux1>0){
    //     fprintf(ListaUnion, "%s\n", Aux1);
    //     }
    //   }else if(Aux1[0] == Aux2[0]){

        
    //     for(j = 1; j < 35; j++){
    //       if(Aux1[j] < Aux2[j]){
    //         fprintf(ListaUnion, "%s\n", Aux1);
    //         fprintf(ListaUnion, "%s\n", Aux2);
    //         break;
    //       }else if(Aux1[j] > Aux2[j]){
	// 		fprintf(ListaUnion, "%s\n", Aux2);
    //         fprintf(ListaUnion, "%s\n", Aux1);
    //         break;
	// 		}else if(Aux1[j] == '\0' && Aux1[j] == '\0'){
    //         fprintf(ListaUnion, "%s\n", Aux1);
    //         fprintf(ListaUnion, "%s\n", Aux2);
    //         break;
    //       }else{
	// 		  puts("algo no cuadra");
	// 	  }
    //       }
         
    //   }
      
    
      //#############################################################################
   

		// cerramos los archivos para que en la proxima iteracion se pueda escribir o leer sobre ellos
		// fclose(textoAuxiliar);yyyyyyyyyyyy
		fclose(ListaUnion);
		fclose(ListaUno);
		fclose(ListaDos);
		
		contador++;
		division = division *2;
		// printf("=========================================================\n\n");
		// sleep(3);
 	}
  
}  


  
