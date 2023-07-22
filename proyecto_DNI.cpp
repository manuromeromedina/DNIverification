#include<stdio.h>     //librería que incluye entrada y salida estándar en C ('printf' and 'scanf')
#include<stdlib.h>    //proporciona funciones de utilidad como 'malloc()' para asignar memoria dinámicamente y 'exit()' para terminar el programa
#include<iostream>    //librería que incluye entrada y salida estándar en C++ ('cout' and 'cin')
#include<conio.h>     //función getch() obtiene un caracter del teclado sin que se muestre en la pantalla (UP AND DOWN FOR MINIGAMES)
#include<string.h>    //trabajar sobre cadena de caracteres en C. 
using namespace std;

void borrar(char a[]){
    for(int i=0; i<11;i++){
        if(a[i]=='\n'){
            a[i]='\0';
        }
    }
}

void extraer(char b[]){
    int doc[8], numero, limite;
    limite=strlen(b);  //strlen() me da la longitud de la cadena. En este caso el limite tendrá que ser igual a dicha longitud

    if(limite != 8){
        cout<<"DNI INVALIDO"<<endl;   // nos plantea que si nuestro limite es menor o mayor a 8 
    }                                 // entonces nos devuelve un "error"

    if(limite == 8){              //en cambio, si es igual a 8, entonces entra en el bucle for
        for(int i=0;i<8;i++){     // donde en cada iteración, se toma el caracter de la posición i
            numero=b[i]-48;       // del arreglo b y se le resta el valor correspondiente en ASCII
            doc[i]=numero;  //luego se almacenan los valores enteros en el arreglo documento
        }
    }
    
 // EMPIEZA LA VERIFICACIÓN DE UN DNI

 int documento[8], suma, ultimo,ultimonum;  //se declara variable y arreglo de 8 posiciones

    if(doc[0]==1 || doc[0]==2){    //ve si la primera posicios es 1 o 2
        if(doc[2]>0 && doc[2]<6){  // ve si la tercera posicion es mayor a 0 y menor a 6
             for(int i=0;i<7;i+=2){   
             documento[i]=doc[i]*2;  //a los digitos en posiciones pares se las multiplica por 2 y se las almacena en el arreglo 'documento'
                 if(documento[i]<=8){  
                    documento[i]-=7;
                 }
            }

            for(int i=1;i<7;i+=2){  // a los digitos en posiciones impares se los almacena directamente en el arreglo 'documento'
             documento[i]=doc[i];
             }
        
            
            suma=0;  //se incializa en 0
        
            for(int i=0;i<8;i++){        //suma los elementos del arreglo documento[i]
             suma=suma+documento[i];
             }

                if(suma==10){   
                    ultimo=0;
                }
                else if(suma>10 && suma<20){
                    ultimo=20;
                }else if(suma>20 && suma<30){
                    ultimo=30;
                }else if(suma>30 && suma<40){
                    ultimo=40;
                } else cout<<"DNI INCORRECTO"<<endl;

                 ultimonum=ultimo-suma;

                if(ultimonum==doc[7]){
                    cout<<"DNI VERIFICADO"<<endl;
                } else cout<<"DNI NO VERIFICADO"<<endl;
            
    
         } else cout<<"DNI INCORRECTO"<<endl;
    }

}


int main (){

     char d[11], op;

     do{
        cout<<"Ingrese numero de documento"<<endl;
        fgets(d,11,stdin);   //acá lee el numero de documento ingresado
        
        //fgets() se usa para leer cadena de caracteres sin desvordamiento de bufers

        borrar(d);
        extraer(d);

        cout<<endl;
        cout<<endl;

        cout<<"Desea ingresar otro numero? (S/N)"<<endl;
        fflush(stdin); //limpieza de bufer
        op=getch();

        cout<<endl;

     }while(op=='S'||op=='s');

     system("pause");
     return 0;

}


