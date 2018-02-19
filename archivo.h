void mostrarBitMap(){
        bitmap bits;
        int last=0,temporal;

        FILE* escritor = fopen("bitmap.bin", "rb");

        fseek(escritor, 0, SEEK_SET);


        int j=0;
        while(1){

            fread(&bits,sizeof(bitmap),1, escritor);


             if(last == ftell(escritor))
                break;
             else
                last= ftell(escritor);


             for(j=0; j<20; j++){

                    if(j%5==0)
                        printf("\n");

                    printf("%d ", bits.bits[j]);


                    //temporal= ftell(archivo);

            }
            printf("\n");
        }

        fclose(escritor);




}
void agregarCadena (char * cadena){






}


void crearArchivos (){

        //arreglo de inodos para escribirlos en una sola instruccion posteriormente

        inodo ino[20];
        int i=0;
        for(i=0; i<20; i++){
          ino[i].next=0;
        //ino.next=1;


        }

        //bitmap de 20 posiciones
        bitmap bits;


        /*
            Se creara el archivo de un tamano fijo de 2MB
            utilizando el comando de linux dd
        */
        char comando[500];

        //limpiamos la cadena del comando a ejecutarse

        memset(&comando[0], 0, sizeof(comando));
        //asignamos el comando necesario
        strcat(comando, "dd if=/dev/zero of=inodo.bin bs=KB count=4");
        //realizamos la ejecucion del comando

        system(comando);
        system("clear");
        free(comando);


        FILE* escritor = fopen("inodo.bin", "rb+");

        fseek(escritor, 0, SEEK_SET);

        fwrite(&ino, sizeof(inodo), 20, escritor);

        /*

        inodo prueba;
        fseek(escritor, 0, SEEK_SET);
        int j=0;

        for(j=0; j<20; j++){

            fread(&prueba,sizeof(inodo),1, escritor);
            printf("%d next \n", prueba.next);
        }*/

        fclose(escritor);


        escritor = fopen("bitmap.bin", "wb+");
        fseek(escritor, 0, SEEK_SET);

        fwrite(&bits, sizeof(bitmap), 1, escritor);
        fclose(escritor);





}
