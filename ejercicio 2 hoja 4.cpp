/*Ejercicio#2
Una persona desea realizar un muestreo con un numero de personas para determinar el porcentaje de
niños, jóvenes, adultos y adultos mayores que existen en la zona en donde vive.
La categoría se determina en base a la siguiente tabla:
Teniendo en cuenta que para el muestreo de personas no será mayor a 50, realice un programa que en
primer lugar reciba como dato el numero de personas del muestreo y luego por cada persona permita el
ingreso de su edad y grabar todo a un archivo. El programa deberá leer los datos del archivo y mostrar
como resultado el porcentaje de personas que hay por cada una de las categorías.
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>	
#include <string>	
using namespace std;
void grabar_archivo();
void leer_archivo();

int main(){
	grabar_archivo();
	leer_archivo();	
}
	
void grabar_archivo(){
	float muestreo=0;
	float ninos=0;
	float jovenes=0;
	float adultos=0;
	float adultos_mayores=0;
	int edad=0;
	string s;
	
	cout<<"Ingrese el numero de personas para el muestreo: "<<endl;
	cin>>muestreo;
	if (muestreo>=1 and muestreo<=50){
		for (int i=1; i<=muestreo; i++){
			cout<<"Ingrese la edad: "<<endl;
			cin>>edad;	
			if (edad>=0 and edad<=12){
				ninos+=1;
			}else if( edad>=13 and edad<=29)
				jovenes+=1;
			else if( edad>=30 and edad<=59)
				adultos+=1;	
			else if( edad>=60)
				adultos_mayores+=1;
		}
	}
	cout<<"El muestreo es de: "<<muestreo<<"\t"<<"\t"<<"Porcentaje de niños \t"<<ninos<<"%\t"<<"Porcentaje de jovenes \t"<<jovenes<<endl;
	
	cout<<" Porcentaje de adultos \t"<<adultos<<"% Porcentaje de adultos mayores \t"<<adultos_mayores<<"%";
	ofstream grabararchivo;
	try {
		grabararchivo.open("muestra.txt",ios::app);
		grabararchivo<<muestreo<<"\t"<<"\t"<<ninos<<"\t"<<jovenes<<"\t"<<adultos<<"\t"<<"\t"<<adultos_mayores<<endl;
		grabararchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
	cout<<"\n"<<"Muestreo total"<<endl;
	cout<<"Personas	ninos jovenes adultos adultos_mayores"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("muestra.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
}		

void leer_archivo(){
	ifstream archivo;
	float m,n,j,a, am;
	try{	
		archivo.open("muestra.txt",ios::in);
		
		while (archivo >>m >> n>> j>>a>>am){	
			n= (n/m)*100;	
			j= (j/m)*100;
			a= (a/m)*100;
			am=(am/m)*100;
		}	
		archivo.close();
		cout<<"Porcentajes de cada categoría: "<<endl;
		cout<<" Categoria \t"<<" Edad "<<endl;
		cout<<" Ninos\t"<<"\t 0-12 \t"<<"="<<n<<"%"<<endl;
		cout<<" Jovenes\t"<<"13-29 \t"<<"="<<j<<"%"<<endl;
		cout<<" Adultos\t"<<"30-59 \t"<<"="<<a<<"%"<<endl;
		cout<<" AdultosM\t"<<">60 \t"<<"="<<am<<"%"<<endl;
	
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
	
	
}
