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
             printf("Bitmap %d \n", temporal);
             for(j=0; j<20; j++){
                    if(j%5==0)
                        printf("\n");
                    printf("%d ", bits.bits[j]);
             }
             temporal++;
            printf("\n");
        }

        fclose(escritor);

}

void agregarCadena (char * cadena){

        char entrada[1000]="";
        strcpy(entrada, cadena);




        bitmap bits;
        inodo ino;


        int last=0, aux=0, espacio=0;

        FILE* escritor = fopen("bitmap.bin", "rb+");

        fseek(escritor, 0, SEEK_SET);



        int j=0;
        while(!espacio){

             fread(&bits,sizeof(bitmap),1, escritor);

             if(last == ftell(escritor))
                break;
             else
                last= ftell(escritor);
             for(j=0; j<20; j++){
                  if(bits.bits[j])
                    aux++;
                  else{

                    espacio=1;
                     break;
                }
             }
        }

        fclose(escritor);

        int tamano=0, restante=strlen(entrada);

        tamano=restante/160;


        if(restante%160){
            tamano++;
        }


        fopen("inodos.bin", "rb+");
        fseek(escritor,aux*sizeof(inodo), SEEK_SET );
        fread(&ino, sizeof(inodo),1, escritor);


        while(restante){

        }



}


void crearArchivos (){

        //arreglo de inodos para escribirlos en una sola instruccion posteriormente
        int direccion=0;
        int bandera=1;
        inodo ino[20];


        int i=0;
        for(i=0; i<20; i++){

            if(bandera){
                ino[i].apInd1=direccion + sizeof(inodo);

                ino[i].apInd2=direccion + 2* sizeof(inodo);
                direccion= direccion + 2* sizeof(inodo);


            }else{
                ino[i].apInd1=-1;
                ino[i].apInd2=-1;
            }
            bandera=!bandera;
            printf("%d bandera \n", bandera);

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



        FILE* escritor = fopen("inodo.bin", "rb+");

        fseek(escritor, 0, SEEK_SET);

        fwrite(&ino, sizeof(inodo), 20, escritor);


        fclose(escritor);


        escritor = fopen("bitmap.bin", "wb+");
        fseek(escritor, 0, SEEK_SET);

        fwrite(&bits, sizeof(bitmap), 1, escritor);
        fclose(escritor);





}
