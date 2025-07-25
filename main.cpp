#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class Personaje { ROJO, AZUL, AMARILLO, VERDE };

enum class TipoCasilla {
    NORMAL,
    CASILLA_DE_OCA,
    PUENTE,
    POSADA,
    POZO,
    LABERINTO,
    CARCEL,
    CALAVERA,
    JARDIN_DE_OCA
};

class Tablero{
protected:
    Jugador jugadores[4];
    Casilla casillas[63];
public:
    void iniciarJuego(){

    }

    Casilla* obtenerCasilla(int pos){

    }

    void moverJugador(Jugador *jugadores, int pasos){

    }
};

class Casilla {
protected:
    int pos_;
public:
    explicit Casilla(int pos) : pos_(pos) {}
    virtual ~Casilla() = default;

    virtual int realizarAccion(Jugador& jugador) = 0; // devuelve nueva posición
    int getPos() const { return pos_; }
};

class CasillaNormal : public Casilla {
public:
    using Casilla::Casilla;
    int realizarAccion(Jugador&) override { return pos_; }
};

class CasillaEspecial : public Casilla {
    TipoCasilla tipo_;
public:
    CasillaEspecial(int pos, TipoCasilla tipo)
        : Casilla(pos), tipo_(tipo) {}

    int realizarAccion(Jugador& jugador) override;
    TipoCasilla getTipo() const { return tipo_; }
};

int CasillaEspecial::realizarAccion(Jugador& jugador){
    switch (_tipo) {
    case tipoCasilla::PUENTE:
        cout<<"Del puente a la posada. Avanza a la casilla 12."<<endl;
        return 12;
        break;
    default:
        break;
    }
}

class Jugador {
    Personaje color_;
    string    nombre_;
    int       posicion_{0};
    Tablero  *tablero_;

    static int tirarDadosInterno() {
        static random_device rd;
        static mt19937 gen(rd());
        static uniform_int_distribution<int> dist(1, 6);
        return dist(gen);
    }

public:
    Jugador(Personaje c, string nom, Tablero* t)
        : color_(c), nombre_(move(nom)), tablero_(t) {}

    int  tirarDados()                 { return tirarDadosInterno(); }
    void cambiarPosicion(int nueva)   { posicion_ = nueva; }

    void jugarTurno() {
        int d = tirarDados();
        cout << nombre_ << " tiró " << d << '\n';
        tablero_->moverJugador(*this, d);
        cout << nombre_ << " está en " << posicion_ << '\n';
    }

    int  getPos() const { return posicion_; }
    const string& getNombre() const { return nombre_; }
};


class Personaje :



int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
