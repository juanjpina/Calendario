/**************************************
* NOMBRE: #Juan Jose#
* PRIMER APELLIDO: #Pina#
* SEGUNDO APELLIDO: #Agudo#
* DNI: #34.793.036-Q#
* EMAIL: #juanjpina@gmail.com#
***************************************/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
int p;

int menu,i;
int dia,mes,anno;
int nuevo_mes;

const int dias=10; //constantes de array actividades
const int carac=1001;

typedef char tabla[dias][carac];//array para actividades
tabla actividades;

typedef char descanso[26]; //array para comprobar descanso
descanso pal="Dia de descanso.";
int ndia,nmes,nanno;
int n_dia,n_mes,n_anno;//variables calendario numero 2
int estado,estados;
//estado=Buscar_Estado(contD,mes,anno);
/* variables calendario*/
//int dia,mes,anno;
int b,z,x;
int contD;
int dia1;
int d=0;
int c=0;
/*--------------------*/


void Grabar_actividades(const tabla actividades){ //1. funcion para grabar array
//const int dias=10;
//const int carac=5;
//typedef char tabla[dias][carac];

    for(int i=0; i<dias; i++){
         printf("Actividad del dia %d? ",i+1);
          fflush(stdin);
          scanf("%[^\n]c",&actividades[i]);

          }
           //printf("%d\n",strlen(actividades[i]));
          if((strlen(actividades[i]))>=carac){
                 // printf("%d",strlen(actividades[i]));
            i--;}
            //printf("%d",strlen(actividades[i]));

  }//void

 void Mostrar_Actividades(const tabla actividades){ //2.funcion para mostrar array
    for(int i=0; i<dias; i++){

    if(i<=9){
        printf("Dia%d\n",i+1);
        printf("====\n");
        printf("%s\n", actividades[i]);}

      else {printf("Dia%d\n",i+1);
        printf("======\n");
        printf("%s\n\n", actividades[i]);}
    }
  }//void

int fecha(int xdia, int xmes, int xanno){//3.funcion para recoger fecha inicio depostes
        printf("Dia?");
        scanf("%d",&dia);
        printf("\n");
        printf("Mes?");
        scanf("%d",&mes);
        printf("\n");
        printf("Anno?");
        scanf("%d",&anno);
        return dia;
        return mes;
        return anno;
  }//void


/*-------calendario----------------*/

int CalculoDeDias(int mes, int anno){
  switch(mes){ //calculo de los dias en los meses
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
  return 31;
  break;
  case 4:
  case 6:
  case 9:
  case 11:
  return 30;
  break;
  case 2:
  if(anno %4!=0 || (anno%100==0 && anno%400!=0)){
    return 28;//"no es bisiesto"
    }else{return 29;
  }
  break;
  default:;
  }
}

int Mes_ano(int mes){ //imprime el mes en texto en pantalla
  switch(mes){
    case 1: printf ("ENERO     ");
    break;
    case 2: printf("FEBRERO   ");
    break;
    case 3: printf("MARZO     ");
    break;
    case 4: printf("ABRIL     ");
    break;
    case 5: printf("MAYO      ");
    break;
    case 6: printf("JUNIO     ");
    break;
    case 7: printf("JULIO     ");
    break;
    case 8: printf("AGOSTO    ");
    break;
    case 9: printf("SEPTIEMBRE");
    break;
    case 10: printf("OCTUBRE   ");
    break;
    case 11: printf("NOVIEMBRE ");
    break;
    default:printf("DICIEMBRE ");
    }
  }

int DiaSemana (int anno, int mes) {//lunes=1..domingo=7
                                    //Calculo de los meses de cuando empiezan
  int a, y, m, diaSemana,dia1;

  a = (14-mes) / 12;
  y = anno - a;
  m = mes + (12*a) - 2;
  dia1 = (dia + y + (y/4) - (y/100) + (y/400) + (31*m) / 12) % 7;
  if (dia1==0) {
    dia1=7;
  }
  return dia1;
}

int LineasCalendario(int mes, int anno){  //para indicar cuantos semanas tiene el mes.

  if( CalculoDeDias(mes,anno)==31 && DiaSemana(anno,mes)==5){
    return 6;}

    else if( CalculoDeDias(mes,anno)==31 && DiaSemana(anno,mes)==6){
    return 6;}

    else if( CalculoDeDias(mes,anno)==31 && DiaSemana(anno,mes)>=7){
    return 5;}

    else if(CalculoDeDias(mes,anno)==30 && DiaSemana(anno,mes)==6 ){
    return 6;}

    else if( CalculoDeDias(mes,anno)==28 && DiaSemana(anno,mes)==7){
    return 4;}

    else{return 5;}
}



int Buscar_Estado(int busca_dia,int busca_mes,int busca_anno,int p){//imprime numero o letra

if ((busca_dia>=dia) && (busca_dia<=dia+9) && (mes==busca_mes) && (anno==busca_anno)){
    if(strcmp((actividades[p]),pal)==0){
                      return 55;
                }else{
                      return 66;
                      }
}
else{
  return busca_dia;
}
}//int



int NuevoCalendario(int ndia, int nmes, int nanno){

  if (contD>=CalculoDeDias(mes,anno)){

        mes=mes+1;
        nuevo_mes=mes+1;



        printf("nuevo mes");

      if(mes>=12){

      anno=anno+1;
          printf("nuev ano");
        }
      }

}

int Nuevo_Buscar_Estado(int buscar_dia,int buscar_mes,int buscar_anno,int nuevo_mes,int p){

 if((buscar_dia>=dia) && (buscar_dia<=dia+9) && (p<=9) ){

      if(strcmp((actividades[p]),pal)==0){
                      return 55;

                }else{
                      return 66;
                      }


      }





else{
  return buscar_dia;
}

}//int







int main(){

do{

printf("1. Introducir plan de entrenamiento\n");
printf("2. Listar plan de entrenamiento\n");
printf("3. Introducir fecha de inicio del plan\n");
printf("4. Mostrar plan en el calendario\n");
printf("5. Salir del programa\n");
scanf("%d",&menu);



  switch(menu){
    case 1:
      Grabar_actividades(actividades);
      break;

    case 2:
      Mostrar_Actividades(actividades);
      break;

    case 3:
   /*     printf("Dia?");
        scanf("%d",&dia);
        printf("\n");
        printf("Mes?");
        scanf("%d",&mes);
        printf("\n");
        printf("Anno?");
        scanf("%d",&anno);*/
        fecha(dia,mes,anno);
        p=0;
      break;

    case 4:

        if((anno>=1601)&&(anno<=3000)&&(mes>=1)&&(mes<=12)){
            printf("dia %d",dia);
            Mes_ano(mes); printf("             %4d\n",anno);
            printf("===========================\n");
            printf("LU  MA  MI  JU  VI | SA  DO\n");
            printf("===========================\n");

  contD=0;
  z=1;
i=0;

for (int y=1; y<=LineasCalendario(mes,anno); y++){
         if(((DiaSemana(anno,mes))!=7)&& (y==1)){
                    for(int b=1; b<=(DiaSemana(anno,mes)); b++){
                        if(b==5){printf(" . ");}
                        else { printf(" .  ");}
                        z=z+4;
                        if (z==21){printf("| ");}
                    }//for
           }//if

//prueba 1--------------------------------------------------------

  //for (int x=z; x<=27; x++){

 //  if ((x-1)%4==0){
            /*if(contD==dia || x>=27){
           while(i<=dias-1){
             if(contD<=CalculoDeDias(mes, anno)){

              if((x-1)%4==0){
                if(strcmp((actividades[i]),pal)==0){
                      printf(" D");
                      x++;
                      i++;
                      contD++;
                }else{
                      printf(" C");
                      x++;
                      i++;
                      contD++;}
                 }
            if(x==26){
                   printf("\n");x=1;}

               else if (x==18 ){
                      printf(" |");x++;}

               else if (x==19){
                      printf(" ");x++;}

               else if (((x-1)%4==2)){
                      printf("  ");
                      x++;}
               else if(i==dias){
                 printf("  ");x++;}
               else {
                    x++;}
              }
              }//while

              }//if contd*/


            /*     if(contD<=(CalculoDeDias(mes,anno))-1){
                   contD++;
                  // if(x==19){printf(" ");}
                   printf("%2d",Buscar_Estado(contD,mes,anno));}
                   else{printf(" .");}
       }//if x-1
                       /*  else if(x==27){
                          printf("\n");}*/

                    /*     else if (x==18 ){
                          printf(" |");}

                         else if (x==19){
                          printf(" ");}

                         else if (((x-1)%4==2)){
                          printf("  ");}

        }*/

 //-----------------------------------------------------------------------------------------

        for (int x=z;x<=27;x++){
                            if ((x-1)%4==0){

                                   if(contD<=(CalculoDeDias(mes,anno))-1){
                                     contD++;
                                      estado=Buscar_Estado(contD,mes,anno,p);
                                      if (estado==55)
                                       {printf (" D");p++;}
                                      else if (estado==66)
                                      { printf (" C");p++;}
                                      else
                                      {printf("%2d",estado);}

                                    }
                                     else{
                                      printf(" .");}}

                                   else if (x==18 ){
                                    printf(" |");}

                                   else if (x==19){
                                    printf(" ");}

                                   else if (((x-1)%4==2)){
                                    printf("  ");}

                                  /* else if ((x-1)%4==2){
                                    printf("");}*/

                                 /* else if((x==13)){
                                    printf("");}*/

                                 /*  else if((x==20)){
                                              ;}*/
                                 /*  else {
                                    printf("");}*/

                                   }




printf("\n");
z=1;
}//for
 }//if


 //NUEVO CALENDARIO--------------------------------------
if(p<9){

        if (contD>=CalculoDeDias(mes,anno)){
                nuevo_mes=mes+1;
                mes=mes+1;

                printf("nuevo mes");

              if(mes==13){

                anno=anno+1;
                mes=1;
                  printf("nuev ano");
                }
              }//if






 printf("\n");
    dia=1;
    if((anno>=1601)&&(anno<=3000)&&(mes>=1)&&(mes<=12)){
            printf("dia %d",dia);
            Mes_ano(mes); printf("             %4d\n",anno);
            printf("===========================\n");
            printf("LU  MA  MI  JU  VI | SA  DO\n");
            printf("===========================\n");

  contD=0;
  z=1;
i=0;

for (int y=1; y<=LineasCalendario(mes,anno); y++){
         if(((DiaSemana(anno,mes))!=7)&& (y==1)){
                    for(int b=1; b<=(DiaSemana(anno,mes)); b++){
                        if(b==5){printf(" . ");}
                        else { printf(" .  ");}
                        z=z+4;
                        if (z==21){printf("| ");}
                    }//for
           }//if

        for (int x=z;x<=27;x++){
        if ((x-1)%4==0){

               if(contD<=(CalculoDeDias(mes,anno))-1){
                 contD++;
                  estados=Nuevo_Buscar_Estado(contD, mes, anno,nuevo_mes,p);
                  if (estados==55)
                   {printf (" D");p++;}
                  else if (estados==66)
                  { printf (" C");p++;}
                  else
                  {printf("%2d",estados);}

                }
                 else{
                  printf(" .");}}

               else if (x==18 ){
                printf(" |");}

               else if (x==19){
                printf(" ");}

               else if (((x-1)%4==2)){
                printf("  ");}

              /* else if ((x-1)%4==2){
                printf("");}*/

             /* else if((x==13)){
                printf("");}*/

             /*  else if((x==20)){
                          ;}*/
             /*  else {
                printf("");}*/

               }




printf("\n");
z=1;
}//for
 }
}//if condicion de entrar






    break;
    default:;
    }//switch
 }while(menu!=5);
}//int main
