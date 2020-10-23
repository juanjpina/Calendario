/**************************************
* NOMBRE: #Juan Jose#
* PRIMER APELLIDO: #Pina#
* SEGUNDO APELLIDO: #Agudo#
* DNI: #34.793.036-Q#
* EMAIL: #juanjpina@gmail.com#
***************************************/

#include<stdio.h>
#include<ctype.h>

int dia,mes,anno,z,x;
int b;
int contD;
int dia1;




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



int main(){

            printf("%cMes (1....12)?",168);
            scanf("%d",&mes);

            printf("%cA%co(1601....3000)?",168,164);
            scanf("%d",&anno);
            printf("\n");



        if((anno>=1601)&&(anno<=3000)&&(mes>=1)&&(mes<=12)){

            Mes_ano(mes); printf("             %4d\n",anno);
            printf("===========================\n");
            printf("LU  MA  MI  JU  VI | SA  DO\n");
            printf("===========================\n");


contD=0;
z=1;

for (int y=1; y<=LineasCalendario(mes,anno); y++){



         if(((DiaSemana(anno,mes))!=7)&& (y==1)){

                    for(int b=1; b<=(DiaSemana(anno,mes)); b++){
                        if(b==5){printf(" . ");}

                        else { printf(" .  ");}
                        z=z+4;
                        if (z==21){printf("| ");}
                    }
           }



                  for (int x=z;x<=27;x++){
                            if ((x-1)%4==0){
                              if(contD<=(CalculoDeDias(mes,anno))-1){
                                  contD++;
                                  printf("%2d",contD);}
                                    else{printf(" .");}
                                  }

                                  else if (x==18 ){
                                    printf(" |");}

                                   else if (x==19){
                                    printf(" ");}

                                   else if (((x-1)%4==2)){
                                    printf("  ");}

                                   else if ((x-1)%4==2){
                                    printf("");

                                  }else if((x==13)){
                                    printf("");
                                  }
                                   else if((x==20)){
                                              ;}
                                   else {
                                    printf("");
                                   }
                    }//for



printf("\n");
z=1;
}//for
 }
}
