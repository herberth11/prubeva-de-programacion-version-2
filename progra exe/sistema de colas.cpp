//codigo fuente: sistema de colas, llamado por voz
//asignatura: programacion 1.
//desarrollado por: Herberth Ovidio Jurado Maradiaga.
//carnet: JM18006
//catedraitca: ingeniera Ligia Astrid Hernandez.
#include <iostream>
#include <windows.h>
using namespace std;

void error();

int menu(int opcion, int numero);/*se declara esta funcion que recibira el dato
de la variable opcion que se declara en la funcion main, esta contendra
el menu de opcines que se le presentaran al usuario.*/

int generar(int eleccion, int opcion, int numero);/*en esta funcion se una instruccion que le pedira al
usuario que ingrese un numero*/

int ingresar(int des, int opcion, int eleccion, int numero);/*esta funcion le pedira al usuario que ingrese el numero que desea generar*/

int menu_generar(int op);/*este menu nos mostrara las opciones que tendra el usuario
despues de ingresar el numero que desea generar*/
int menu_Guardar(int numero);

//esta es una funcion de tipo void porque no retornara nada solo se ejecutara
//para llamar por vos un cliente
void llamarNum(int numero, int opcion);

//al igual que la anterior solo se ejecutara para borrar un numero
void eliminarNum(int numero, int opcion);

int main(){
	system ("color f0");
	int opcion;/*en esta bariable almacenaremos la opcion que el usuario
	elija*/
	int numero;/*declaromes esta variable en el main debido a que se utilizara en
	varias funciones*/
	numero = 0;//y la igualamos a cero para pasarle el valor que tome en las funciones
	cout << "BIENVENIDO AL SISTEMA DE COLAS" << endl;/*iniciamos dandole la bienvenida al
	usuario que sera la primer consola que aparecera al ejecutar el programa*/
	cout << "     DE HERBERTH MARADIAGA" << endl;
	char soundfile[] = "C:/Users/Herberth Maradiaga/Desktop/progra exe/Bienvenida.wav" ;
	PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC);
	
	system("pause");
	cout << endl;
	/*el bucle se repetira hasta que el usuario ingrese uno o dos que son las opciones
	del menu que se presentan*/
	do
	{
		cout << "     1. ingresar al sistema" << endl;
	    cout << "           2. salir" << endl;
	    cin >> opcion;
	    error();
	}while (opcion != 1 && opcion != 2);
	
	
	if (opcion == 1)
	{
		menu(opcion, numero);/*si el usuario presiona uno, se ejecutara la funcion menu
		que recibe los datos de la variable opcion, y el dato de la variable
		numero porque se ejecuta una funcion que equiere ese dato*/
	}
	else if (opcion == 2)
	{
		system("cls");/*si el usuario preciona dos se limpiara la pantalla y se le dara
		la instrucion que presine enter para salir, luego se cerrara el programa*/
		system ("pause");
	}
	
	return 0;
}

void error(){
	system ("cls");
	 while (cin.fail()){//validamos el ingreso de solo datos numericos
	    	system("cls");
	    	cin.clear();
	    	cin.ignore(1000,'\n');
	    	cout << "Error de datos, intente de nuevo" << endl;
		}
}

int menu(int opcion, int numero){/*esta funcion es una funcion que le muestra al usuario un menu de opciones
empezara limpiando la pantalla de procesos anteriores y luego mostrara el menu*/
	system ("cls");
	int eleccion;/*en esta variable se almacenara el dato que el usuario ingrese*/
	cout << "   MENU OPCIONES" << endl;//titulo de la pantalla
	cout << endl;
	/*si el usuario ingresa un numero diferente de 1, 2, 3 o 4 se repetira el siclo*/
	do
	{
		cout << "1. generar numero." << endl;
	    cout << "2. llamar numero." << endl;
	    cout << "3. eliminar numero. " << endl;
	    cout << "4. salir." << endl;
	    cin >> eleccion;
	    //mientras el usuario ingrese daros no numericos seejecutara este siclo
	    error();
	    
	}while (eleccion < 1 || eleccion > 4);
	/*si la eleccion del usuario es igua al uno se ejecutara la funcion generar*/
	if (eleccion == 1)
	{
		generar(eleccion, opcion, numero);
	}
	/*sino es igua a uno se condiciona que si es igual a dos se
	ejecute la funcion llamarNum*/
	else if (eleccion == 2){
		llamarNum(numero, opcion);
	}
	/*sino es igual a uno ni a dos entonces se condiciona que si es
	igual a tres se ejecute la funcion elimniarNum*/
	else if (eleccion = 3){
		eliminarNum(numero, opcion);
	}
	/*y sino es igual a uno, a dos ni atres se condiciona que
	si es igual a cuatro se salga del programa*/
	else if(eleccion == 4)
	{
		system ("cls");
		cout << endl;
		cout << "precione enter para salir" << endl;
	}
	
	return eleccion;
}

int generar(int eleccion, int opcion, int numero)
{/*la funcion generar preguntara al usuario si desea generar un numero si la respuesta de
este es si se ejecutara la funcion ingresar, si la respuesta es no se le preguntara si
quiere salir del programa o volver al menu*/
	int des;/*en esta varible se almacenara el deseo del usuario de generar o no un nuevo numero*/	
    	
    	cout << "desea generar un numero?" << endl;/*le preguntamos
		al usuario si desea generar un numero*/
    	cout << "1. si" << endl;
    	cout << "2. no" << endl;
    	cin >> des;
    	
	    int des1;/*esta variable se coloca en caso del que el usuario no desee generar un numero
	    se le presentara un menu en el que el elijira entre volver al menu y salir de programa, esa
	    eleccion se guardara en esta variable*/
    	if (des == 1){// si la respuesta del usuario es si
    		ingresar(des, opcion, eleccion, numero);
		}
		else if (des == 2){
			cout << "1. volver al menu" << endl;
			cout << "2. salir" << endl;
			cin >> des1;
			/*si el usuario elige volver al menu se ejecutara la funcion menu,
			si elige salar se ejecutara un system pause para que solo precione una
			tecla y pueda salir del programa*/
			if (des1 == 1){
				menu(opcion, numero);
			}
			else
			{
				system("pause");
			}
		}
	return des;
}

int ingresar(int des, int opcion, int eleccion, int numero){
	numero =0;/*aqui se almacenara el numero que el usuario ingrese,
	los numeros estaran entre 1 y nueve para faciliatar la reproduccion del
	audio, ya que los audios que se añadiran para llamar los numeros seram del uno al nueve.*/
	int men;
	do
    {//se el pide que ingrese in numero, que no debera de ser menor a uno ni mayor a nueve
    //por el hecho de que los auidos que se reproduciran estan entre uno y nueve
	    cout << "ingrese el numero que desea generar." << endl;
	    cin >> numero;
	    error();
    }while (numero < 1 || numero > 9);
    do
    {/*le mostramos un menu al usuario para que elija lo que desea hacer
	con el numero ingresado*/
    	cout << "1. guardar numero" << endl;
    	cout << "2. volver a ingresar el numero" << endl;
    	cout << "3. volver al menu" << endl;
    	cout << "4. salir" << endl;
    	cin >> men;
    	error();
	}while (men < 1 || men > 4);
	/*si el usuario eleije guardar el numero se ejecutara la funcion menu_Guardar
	si elije volver a ingresar el menu la funcion se autollamara, si elije volver al menu
	se ejecutara la funcion menu, y si decide salir se ejecutara un system pause*/
	if (men == 1){
		menu_Guardar(numero);
	}
	else if(men == 2){
		ingresar(des, opcion, eleccion, numero);
	}
	else if(men == 3){
		menu(opcion, numero);
	}
	else if (men == 4){
		system("pause");
	}
	/*esta funcion se ejecutara para preguntarle al usuario si desea
	generar un nuevo numero, aclarar que debido a que no es una lista de numeros
	que se van a ingresar al ejecutar de nuevo esa funcion lo que hara es canviar el
	dato ingresado por el nuevo dato que el usuario va ingresar por lo que no se mostraran
	los dos datos sino solo el mas reciente*/
	generar(eleccion, opcion, numero);
	
return numero;
}

/*en esta funcion lo que aremos es pasar el numero que el usuario ingrese
a un arreglo bidimencinal que tendra nueve casilla*/
int menu_Guardar(int numero)
{
	int numg;/*en esta variable se guardara el numero que el usuario
	ingrese, deberia ser un arreglo para poder guardar varios numeros pero
	sinceramente no lo he podido programar por lo que sera solo un numero*/
	numg =numero;
	cout << "numero del cliente: " << numg << endl;//este numero se mostrara en pantalla
	//si el usuario selecciona guardar el numero
	return numg;
}

void llamarNum(int numero, int opcion){
	/*la funcion llamarNum nos servira para llamar un numero, primero
	inprimira el numero que se haya generado y guaradado en la funcion generar
	luego preguntara al cliente si quiere llamar al cliente*/
	int llamar;
	int llam;
	do
	{
		cout <<"el numero del cliente es: " << numero << endl;
	    cout << "desea llamar el numero" << endl;
	    cout << "1. si" << endl;
	    cout << "2. no" << endl;
	    cin >> llamar;
	    error();
	}while(llamar < 1 || llamar > 2);
	
	/*si el susario elige llamar al cliente se conf¿dicionara para saber el
	numero seleccionado y asi podra reproducir el audio correcto, y como antes 
	se ha condicionado para que solo se ingresen numeros del uno al nueve los audios
	que se produciran seran de ese rango*/
	if (llamar == 1){
		if (numero == 1){
			char soundfile[] = "C:/Users/Herberth Maradiaga/Desktop/progra exe/Uno.wav" ;
	        PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(numero == 2){
			char soundfile[] = "C:/Users/Herberth Maradiaga/Desktop/progra exe/Dos.wav" ;
	        PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(numero == 3){
			char soundfile[] = "C:/Users/Herberth Maradiaga/Desktop/progra exe/Tres.wav" ;
	        PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(numero == 4){
			char soundfile[] = "C:/Users/Herberth Maradiaga/Desktop/progra exe/Cuatro.wav" ;
	        PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(numero == 5){
			char soundfile[] = "C:/Users/Herberth Maradiaga/Desktop/progra exe/Cinco.wav" ;
	        PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(numero == 6){
			char soundfile[] = "C:/Users/Herberth Maradiaga/Desktop/progra exe/Seis.wav" ;
	        PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(numero == 7){
			char soundfile[] = "C:/Users/Herberth Maradiaga/Desktop/progra exe/Siete.wav" ;
	        PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(numero == 8){
			char soundfile[] = "C:/Users/Herberth Maradiaga/Desktop/progra exe/Ocho.wav" ;
	        PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(numero == 9){
			char soundfile[] = "C:/Users/Herberth Maradiaga/Desktop/progra exe/Nueve.wav" ;
	        PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC);
		}
	}
	else if(llamar == 2){
		do
		{/*se le muestran al usuario dos opcines
		que poda elegir*/
			cout << "1. volver al menu" << endl;
		    cout << "2. salir" << endl;
		    cin >> llam;
		    error();
		}while(llam < 1 || llam > 2);
		//si elije la opcion uno se ejecuta la funcion menu
		//si elije la opcion dos se ejecuta un system pause
		if (llam == 1){
			menu(opcion, numero);
		}
		else
		{
			system("pause");
		}
	}
	do
		{/*se le muestran al usuario dos opcines
		que poda elegir*/
			cout << "1. volver al menu" << endl;
		    cout << "2. salir" << endl;
		    cin >> llam;
		    error();
		}while(llam < 1 || llam > 2);
		//si elije la opcion uno se ejecuta la funcion menu
		//si elije la opcion dos se ejecuta un system pause
		if (llam == 1){
			menu(opcion, numero);
		}
		else
		{
			system("pause");
		}
}
/*la funcion eliminarnum nos servira para borrar el numero que se haya introducido
en las funcones anteriores*/
void eliminarNum(int numero, int opcion){
	int eliminar;
	int eli;
	do
	{
		cout << "el numero del cliente es: " << numero << endl;
	    cout << "desea eliminar el numero: " << endl;
	    cout << "1. si" << endl;
	    cout << "2. no" << endl;
	    cin >> eliminar;
	    error();
	}while(eliminar < 1 || eliminar > 2);
	
	if (eliminar == 1){
		numero = 0;//si el usuario elige eliminar numero el numero
		//sea igual a cero
	}
	else if(eliminar == 2){
		do
		{//si elije no eliminar le numero se le mostrara dos opcines
			cout << "1. volver al menu." << endl;
		    cout << "2. salir." << endl;
		    cin >>eli;
		    error();
		}while(eli < 1 || eli > 2);
		//si el usuario elije laopcion uno volvera al menu principal
		if (eli == 1){
			menu(opcion, numero);
		} 
		else
		{//si elige salir se ejecutara un system pause
			system("pause");
		}
	}
	cout << "no hay clientes: " << numero << endl;
	do
		{//si elije no eliminar le numero se le mostrara dos opcines
			cout << "1. volver al menu." << endl;
		    cout << "2. salir." << endl;
		    cin >>eli;
		    error();
		}while(eli < 1 || eli > 2);
		//si el usuario elije laopcion uno volvera al menu principal
		if (eli == 1){
			menu(opcion, numero);
		} 
		else
		{//si elige salir se ejecutara un system pause
			system("pause");
		}
}
