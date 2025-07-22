#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class jugador {
private:
    string nombre;

public:
    int posicion;
    int dados=0;

    //constructor
    jugador(string n) {
        nombre = n;
    }

    int tirarDados(int dados){
        dados= rand() % 6 + 1;
        return dados;
    }

    int cambiarPosicion(int posicion){
        posicion += dados;
        return posicion;
    }
};

class Casilla {
public:
    int pos;

    virtual int realizarAccion();
};

class CasillaEspecial : public Casilla {
public:
    int realizarAccion(pos){
        switch (pos){
        case 9: pos = 18;
            break;
        case 18: pos = 27;
            break;
        case 27: pos = 36;
            break;
        case 36: pos = 45;
            break;
        case 45: pos = 54;
            break;
        }

    }
};

class tablero {
private:
    casilla tableros[63];
    jugador* jugadores[4];

public:
    tablero() {
        jugadores[0] = new Jugador("Jim");
        jugadores[1] = new Jugador("Pam");
        jugadores[2] = new Jugador("Dwight");
        jugadores[3] = new Jugador("Michael");
    }
};



int main()
{
   srand(time(0));
    return 0;
}
