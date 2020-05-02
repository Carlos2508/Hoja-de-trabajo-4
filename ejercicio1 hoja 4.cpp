/*Ejercicio#1
En la región de la sierra de los Cuchumatanes la compañía Xterminio s.a. , tiene las siguientes tarifas:
Tipo Servicio Costo
 X Hectárea
Además del área a fumigar es mayor a 500.00 hectáreas se tiene un descuento del 5%. Adicionalmente,
si el total a pagar por el servicio es mayor a Q1500.00 se tiene un descuento adicional del 10% sobre el
excedente.
La compañía necesita las estadísticas de los servicios que ha ofrecido a un grupo de agricultores durante
un periodo de tiempo. Por cada servicio debe ingresar los datos siguientes: Tipo de Fumigación (1 a 4) y
el número de hectáreas, toda esta información deberá almacenarse en una base de datos (archivo plano).
Se le pide que realice un programa en C++ que solicite el ingreso de la información de cada servicio
realizado a un grupo de agricultores. El programa deberá de leer los datos del archivo que tiene la
información antes almacenada y mostrar la cantidad de servicios de cada tipo de fumigación, determinar
el tipo servicio con mayor demanda y el monto total pagado por los clientes.
*/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
struct ventas{
	int tipoprod;
	float descuento;
	float precio;
	int unidades;
	float totalvta;
};		
void grabar_archivo();
void leer_archivo();

int main(){
	grabar_archivo();
	leer_archivo();	

}

	
void grabar_archivo(){
	int tipoprod;
	float precio;
	float unidades;
	float descuento;
	float totalvta;
	string s;
	
	cout<<"----- Xtermino S.A -----"<<endl;
	cout<<" Ingrese tipo de servicio: "<<endl;
	cout<<" tipo 1	Mala hierba		 -> 1  - Costo x Hectarea	10.00"<<endl;
	cout<<" tipo 2	Langostas		 -> 2  - Costo x Hectarea	20.00"<<endl;
	cout<<" tipo 3	Gusanos	  		 -> 3  - Costo x Hectarea	30.00"<<endl;
	cout<<" tipo 4	Todo lo anterior 	 -> 4  - Costo x Hectarea	50.00"<<endl;
	cout<<"Indique el tipo de servicio que desea: "<<endl;
	cin>>tipoprod;
	cout<<"Ingrese el numero de hectareas: "<<endl;
	cin>>unidades;	
	if (tipoprod ==1){
		descuento = 0.05;
		precio = 10.00;
		totalvta = unidades*precio;	
	}
	else if (tipoprod==2){
		precio = 20.00;
		totalvta = unidades*precio;	 	
	}
	else if(tipoprod==3){
		precio=30.00;
		totalvta = unidades*precio;	
	}
	else if(tipoprod==4){
		precio=50.00;
		totalvta = unidades*precio;	
	}
	if (totalvta>500){
		totalvta= totalvta-(totalvta*0.05);
	}
	if (totalvta>1500){
		totalvta= totalvta-(totalvta*0.10);
	}
	cout<<"Tipo Prod: "<<"\t"<<tipoprod<<"\t"<<"Precio: "<<"\t"<<precio<<"\t"<<"Hectareas: "<<"\t"<<unidades<<"\t"<<"Total de vta \t"<<totalvta;
	ofstream grabararchivo;
	try {
		grabararchivo.open("agrono.txt",ios::app);
		grabararchivo<<tipoprod<<"\t"<<"\t"<<precio<<"\t"<<unidades<<"\t"<<totalvta<<endl;
		grabararchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
	cout<<"\n"<<"Ventas Actuales"<<endl;
	cout<<"Tipo Prod   Precio  Hectareas  TotalVenta"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("agrono.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
}		

void leer_archivo(){
	ifstream db;
	float tp,d,p,u,tv=0;
	float sumatotal=0;
	float tp1=0;
	float tp2=0;
	float tp3=0;	
	float tp4=0;
	int c1=0, c2=0,c3=0,c4=0;
	try{	
		db.open("agrono.txt",ios::in);
		
		while (db >>tp >> p>> u>>tv){	
			if (tp==1){
				tp1+=tv;
				c1+=1;
			}
			else if (tp==2){
				tp2+=tv;
				c2+=1;
			}	
			else if (tp==3){
				tp3+=tv;
				c3+=1;
			}
			else if (tp==3){
				tp4+=tv;
				c4+=1;	
			}
		}	
		db.close();
		system("CLS");
		cout<<"Cantidades de cada tipo de servicio: "<<endl;
		cout<<" tipo 1 \t"<<c1<<endl;
		cout<<" tipo 2 \t"<<c2<<endl;
		cout<<" tipo 3 \t"<<c3<<endl;
		cout<<" tipo 4 \t"<<c4<<endl;
		cout<<"Monto total de cada tipo de servicio: "<<endl;
		cout<<" tipo 1 \t"<<tp1<<endl;
		cout<<" tipo 2 \t"<<tp2<<endl;
		cout<<" tipo 3 \t"<<tp3<<endl;
		cout<<" tipo 4 \t"<<tp4<<endl;
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
	
	
}

