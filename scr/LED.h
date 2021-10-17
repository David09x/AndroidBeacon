// -*- mode: c++ -*-

#ifndef LED_H_INCLUIDO
#define LED_H_INCLUIDO

// ----------------------------------------------------------
// Jordi Bataller i Mascarell
// 2019-07-07
// ----------------------------------------------------------

// ----------------------------------------------------------
// ----------------------------------------------------------
//Funcion que se usa para saber el tiempo que tarda en recibir el LED la información
//Diseño Entrada:(Real) ---> esperar() ----> Salida:(Nada)
void esperar (long tiempo) {
  delay (tiempo);
}

// ----------------------------------------------------------
// ----------------------------------------------------------
//clase led que tiene un entero que es el led que lo sabremos mediante una ID
//y un booleano que si es verdadero lo encederemos y si es falso estara apagado
//tiene en la parte publica una "funcion" que sirve para saber que led estas manejando y te indica si esta apagado o encendido y 
//su "ID" que es el led que corresponde
class LED {
private:
  int numeroLED;
  bool encendido;
public:

  // .........................................................
  // .........................................................
  LED (int numero)
	: numeroLED (numero), encendido(false)
  {
	pinMode(numeroLED, OUTPUT);
	apagar ();
  }

  // .........................................................
  // .........................................................
  //Sirve para mandar al Led indicado que se encienda.
  //Diseño Entrada(Nada) ----> Encender() ------> Salida(modifica lo de dentro)
  void encender () {
	digitalWrite(numeroLED, HIGH); 
	encendido = true;
  }

  // .........................................................
  // .........................................................
  //Funcion para apagar el Led.
  //Diseño Entrada----> (nada) Apagar() Salida-------> (modifica lo de dentro)
  void apagar () {
	  digitalWrite(numeroLED, LOW);
	  encendido = false;
  }

  // .........................................................
  // .........................................................
  //funcion que permite alternar tanto apagar como encender el LED
  //Diseño Entrada-----> (nada) alternar() Salida------> (modifica lo de dentro)
  void alternar () {
	if (encendido) {
	  apagar();
	} else {
	  encender ();
	}
  } // ()

  // .........................................................
  // .........................................................
  //Funcion que permite durante un tiempo que funcione el LED
  //Diseño Entrada------->(Real) Brillar() Salida------->(modifica lo de dentro)
  void brillar (long tiempo) {
	encender ();
	esperar(tiempo); 
	apagar ();
  }
}; // class

// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------
#endif
