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

vector<_vertex3i> caras;
vector<_vertex3f> colores_caras;
};


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

// Tipo indica si es una figura por revolucion normal o bien un cono o una esfera
// tipo = 0 -> normal, tipo = 1 -> Cono, tipo = 2 -> esfera
// tapa_inf = 0 -> Sin tapa inferior, tapa_inf = 1 -> con tapa inferior
// tapa_sup = 0 -> sin tapa superior, tapa_sup = 1 -> con tapa superior
class _rotacion: public _triangulos3D
{
public:
       _rotacion();
       
void  parametros(vector<_vertex3f> perfil, int num, int tipo, int tapa_inf, int tapa_sup);
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
//  Práctica 2
//************************************************************************

// Clase Cono
class _cono: public _rotacion{
	public:
	_cono(float radio, float altura, int num);
};

// Clase Cilindro
class _cilindro: public _rotacion{
	public:
	_cilindro(float radio, float altura, int num);
};

// Clase esfera
class _esfera: public _rotacion{
	public:
	_esfera(float radio, int num_mer, int num_par);
};

// Clase rotacion Ply

class _rotacion_PLY: public _rotacion{
	public:
	_rotacion_PLY();
	void parametros_PLY(char *archivo, int num);
};
