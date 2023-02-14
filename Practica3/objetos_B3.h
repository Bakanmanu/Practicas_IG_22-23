//**************************************************************************
// Práctica 2 
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>


const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID,SOLID_COLORS} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:

  
	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
vector<_vertex3f> colores_vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_colores();
void 	draw(_modo modo, float r, float g, float b, float grosor);

/* asignación de colores */
void 	colors_random();
void 	colors_chess(float r1, float g1, float b1, float r2, float g2, float b2);


vector<_vertex3i> caras;
vector<_vertex3f> colores_caras;
};

//*************************************************************************
// objetos o modelos
//*************************************************************************

//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=1.0);
};

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

void  parametros(char *archivo);
};

//************************************************************************
// objeto por revolución
//************************************************************************
// tipo indica si es una figura por revolución normal o bien un cono o una esfera
// tipo=0 normal, tipo=1 cono, tipo=2 esfera
// tapa_in=0 sin tapa, tapa_in=1 con tapa
// tapa_su=0 sin tapa, tapa_su=1 con tapa

class _rotacion: public _triangulos3D
{
public:
       _rotacion();
       
void  parametros(vector<_vertex3f> perfil, int num, int tipo, int tapa_in, int tapa_su);
};

 
//************************************************************************
// cilindro
//************************************************************************

class _cilindro: public _rotacion
{
public:
       _cilindro(float radio=1.0, float altura=2.0, int num=12);
};

//************************************************************************
// cono
//************************************************************************

class _cono: public _rotacion
{
public:
       _cono(float radio=1.0, float altura=2.0, int num=12);
};

//************************************************************************
// esfera
//************************************************************************

class _esfera: public _rotacion
{
public:
       _esfera(float radio=1.0, int num1=12, int num2=12);
};


//************************************************************************
// rotacion archivo PLY
//************************************************************************

class _rotacion_PLY: public _rotacion
{
public:
       _rotacion_PLY();
void  parametros_PLY(char *archivo, int num);
};


//************************************************************************
// objeto por extrusión
//************************************************************************

class _extrusion: public _triangulos3D
{
public:
       _extrusion(vector<_vertex3f> poligono, float x, float y, float z);
};


//************************************************************************
// práctica 3, objeto jerárquico articulado excavadora
//************************************************************************

//************************************************************************
// piezas
//************************************************************************

//************************************************************************
// Cilindro Elipse
//************************************************************************

class _cilindroElipse: public _triangulos3D{
	public:
       _cilindroElipse(float ejeP=0.6, float ejeG=1.0, float altura=2.0, int num=16);

};

//************************************************************************
// Esfera Elipse
//************************************************************************

class _esferaElipse: public _triangulos3D{
       public:
       _esferaElipse(float ejeP=0.75, float ejeG=1.0, int num1=6, int num2=6);
};


//************************************************************************
// Pata
//************************************************************************
class _pata: public _triangulos3D{
       public:
              _pata();
              void draw(_modo modo, float r, float g, float b, float grosor);
       float ancho;
       float alto;
       float fondo;
       float radio;

       protected:    
              _cubo cubo;
              _cilindro cilindro;
};


//************************************************************************
// Pinza
//************************************************************************
class _pinza: public _triangulos3D{
       public:
              _pinza();
              void draw(_modo modo, float r, float g, float b, float grosor);
       float ancho;
       float alto;
       float fondo;
       
       protected:
              _cubo cubo;
              _esferaElipse elipse3d;
};

//************************************************************************
// Brazo
//************************************************************************
class _brazo: public _triangulos3D{
       public:
              _brazo();
              void draw(_modo modo, float r, float g, float b, float grosor);
       float ancho;
       float alto;
       float fondo;
              
       protected:
              _cilindro cilindro;
              _pinza pinza;

};

//************************************************************************
// Aguijon
//************************************************************************
class _aguijon: public _triangulos3D{
       public:
              _aguijon();
              void draw(_modo modo, float r, float g, float b, float grosor);
       float ancho;
       float alto;
       float fondo;
       
       protected:
              _esfera esfera;
              _cono cono;
};

//************************************************************************
// Cola
//************************************************************************
class _cola: public _triangulos3D{
       public:
              _cola();
              void draw(_modo modo, float r, float g, float b, float grosor);
       float ancho;
       float alto;
       float fondo;
       
       protected:
              _cono cono;
              _cilindro cilindro;
              _aguijon aguijon;
};

//************************************************************************
// Cabeza
//************************************************************************
class _cabeza: public _triangulos3D{
       public:
              _cabeza();
              void draw(_modo modo, float r, float g, float b, float grosor);
       float ancho;
       float alto;
       float fondo;

       protected:
       _esfera esfera;
       _esferaElipse elipse3d;
};

//************************************************************************
// Escorpion (montaje del objeto final)
//************************************************************************
class _escorpion: public _triangulos3D{
       public:
              _escorpion();
              void draw(_modo modo, float r, float g, float b, float grosor);
       float ancho;
       float alto;
       float fondo;

       /*Insertar valores de animaciones */


       protected:
              _cilindroElipse cuerpo;
              _cola cola;
              _cabeza cabeza;
              _pata pata;
              _brazo brazo;
};