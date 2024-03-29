//**************************************************************************
// Práctica 2 
//**************************************************************************

#include "objetos_B2.h"
#include "file_ply_stl.hpp"


//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido con un único color
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
	int i;
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(r,g,b);
	glBegin(GL_TRIANGLES);
	for(i=0; i<caras.size(); i++){
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
	glEnd();
}

//*************************************************************************
// dibujar en modo sólido con colores diferentes para cada cara
//*************************************************************************

void _triangulos3D::draw_solido_colores(){
	int i;
	glPolygonMode(GL_FRONT, GL_FILL);
	glBegin(GL_TRIANGLES);
	for(i=0; i<caras.size(); i++){
		glColor3f(colores_caras[i].r, colores_caras[i].g, colores_caras[i].b);
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
	glEnd();
}

//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r, float g, float b, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r, g, b, grosor);break;
	case EDGES:draw_aristas(r, g, b, grosor);break;
	case SOLID:draw_solido(r, g, b);break;
	case SOLID_COLORS:draw_solido_colores();break;
	}
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
//vertices
vertices.resize(8);
vertices[0].x=0; vertices[0].y=0; vertices[0].z=tam;
vertices[1].x=tam; vertices[1].y=0; vertices[1].z=tam;
vertices[2].x=tam; vertices[2].y=0; vertices[2].z=0;
vertices[3].x=0; vertices[3].y=0; vertices[3].z=0;

vertices[4].x=0; vertices[4].y=tam; vertices[4].z=tam;
vertices[5].x=tam; vertices[5].y=tam; vertices[5].z=tam;
vertices[6].x=tam; vertices[6].y=tam; vertices[6].z=0;
vertices[7].x=0; vertices[7].y=tam; vertices[7].z=0;

// triangulos
caras.resize(12);

// Base
caras[0]._0=3; caras[0]._1=1; caras[0]._2=0;
caras[1]._0=3; caras[1]._1=2; caras[1]._2=1;

// Frontal
caras[2]._0=0; caras[2]._1=5; caras[2]._2=4;
caras[3]._0=0; caras[3]._1=1; caras[3]._2=5;

// Lat. Der
caras[4]._0=1; caras[4]._1=2; caras[4]._2=5;
caras[5]._0=2; caras[5]._1=6; caras[5]._2=5;

// Lat. Izq
caras[6]._0=0; caras[6]._1=4; caras[6]._2=7;
caras[7]._0=7; caras[7]._1=3; caras[7]._2=0;

// Superior
caras[8]._0=4; caras[8]._1=5; caras[8]._2=6;
caras[9]._0=6; caras[9]._1=7; caras[9]._2=4;

// Trasera
caras[10]._0=2; caras[10]._1=3; caras[10]._2=7;
caras[11]._0=7; caras[11]._1=6; caras[11]._2=2;

// Colores
colores_caras.resize(12);
for(int i=0; i<caras.size(); i++){
	colores_caras[i].r=rand()%1000/1000.0;
	colores_caras[i].g=rand()%1000/1000.0;
	colores_caras[i].b=rand()%1000/1000.0; 
}
}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

//vertices 
vertices.resize(5); 
vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

caras.resize(6);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;

// Colores
colores_caras.resize(6);
for(int i=0; i<caras.size(); i++){
	colores_caras[i].r=rand()%1000/1000.0;
	colores_caras[i].g=rand()%1000/1000.0;
	colores_caras[i].b=rand()%1000/1000.0; 
}
}

//*************************************************************************
// clase objeto ply
//*************************************************************************


_objeto_ply::_objeto_ply() 
{
   // leer lista de coordenadas de vértices y lista de indices de vértices
 
}



void _objeto_ply::parametros(char *archivo)
{
int n_ver,n_car;
int i;

vector<float> ver_ply ;
vector<int>   car_ply ;
 
_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
n_car=car_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

vertices.resize(n_ver);

// vertices
for(i=0; i<vertices.size(); i++){
  vertices[i].x=ver_ply[3*i];
  vertices[i].y=ver_ply[3*i+1];
  vertices[i].z=ver_ply[3*i+2];
}


caras.resize(n_car);

// caras
for(i=0; i<caras.size(); i++){
  caras[i]._0=car_ply[3*i];
  caras[i]._1=car_ply[3*i+1];
  caras[i]._2=car_ply[3*i+2];
}

// Colores
colores_caras.resize(n_car);
for(i=0; i<colores_caras.size(); i++){
  colores_caras[i].r=rand()%1000/1000.0;
  colores_caras[i].g=rand()%1000/1000.0;
  colores_caras[i].b=rand()%1000/1000.0; 
}
}


//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion(){

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num, int tipo, int tapa_inf, int tapa_sup){
	int i,j;
	_vertex3f vertice_aux;
	_vertex3i cara_aux;
	int num_aux;

	// tratamiento de los vértices
	num_aux=perfil.size();

	if(tapa_inf==0 && tapa_sup==0){
		vertices.resize(num_aux*num);
	}else if(tapa_inf==1 && tapa_sup==1){
		vertices.resize(num_aux*num+2);
	}else{
		vertices.resize(num_aux*num+1);
	}

	if(tipo == 1){
		num_aux--;
	}

	for (j=0;j<num;j++){
		for (i=0;i<num_aux;i++){
			vertice_aux.x=	perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
							perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
			vertice_aux.z=	-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
							perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
			vertice_aux.y=	perfil[i].y;
			vertices[i+j*num_aux]=vertice_aux;
		}
	}

	int num_car = 2*num*(num_aux-1)+2*num;

	// tratamiento de las caras 
	caras.resize(num_car);
	int c=0;
	for(j=0; j<num; j++){
		for(i=0; i<num_aux-1; i++){
			caras[c]._0=j*num_aux+i;
			caras[c]._1=((j+1)%num)*num_aux+i+1;
			caras[c]._2=j*num_aux+i+1;
			c+=1;

			caras[c]._0=((j+1)%num)*num_aux+i+1;
			caras[c]._1=j*num_aux+i;
			caras[c]._2=((j+1)%num)*num_aux+i;
			c+=1;
			
		}	
	}
	// tapa inferior
	int total=num_aux*num;

	vertices[total].x=0.0;
	vertices[total].y=perfil[0].y;
	vertices[total].z=0.0;

	for(j=0; j< num; j++){
		caras[c]._0=((j+1)%num)*num_aux;
		caras[c]._1=j*num_aux;
		caras[c]._2=total;
		c+=1;
	}
	
	// tapa superior
	
	vertices[total+1].x=0.0;
	if(tipo != 1)	vertices[total+1].y=perfil[num_aux-1].y;
	if(tipo == 1)	vertices[total+1].y=perfil[1].y;
	vertices[total+1].z=0.0;

	/* 
	for (j=0; j<num; j++){
		caras[c]._0=((j+1)%num)*num_aux;
		caras[c]._1=((j+1)%num)*num_aux+1;
		caras[c]._2=total+1;
		c+=1;
	} 
	 */
	for(j=num_aux; j<=num_aux*num; j+=num_aux){
		caras[c]._0=j-1;
		caras[c]._1=(j+num_aux-1)%(total); // (i+perfil.size())%(vertices.size()-1)
		caras[c]._2=total+1;
		c++;
	}

	//	Colores
	colores_caras.resize(num_car);
	for(i=0; i<colores_caras.size(); i++){
	colores_caras[i].r=rand()%1000/1000.0;
	colores_caras[i].g=rand()%1000/1000.0;
	colores_caras[i].b=rand()%1000/1000.0; 
	}

}





// Objeto Cilindro (Caso especial de rotacion)

_cilindro::_cilindro(float radio, float altura, int num){
	vector<_vertex3f> perfil;
	_vertex3f aux;

	aux.x=radio; aux.y=-altura/2; aux.z=0.0;
	perfil.push_back(aux);
	aux.x=radio; aux.y=altura/2; aux.z=0.0;
	perfil.push_back(aux);

	parametros(perfil,num,0,1,1);
}


// Objeto Cono (Caso especial de rotacion)

_cono::_cono(float radio, float altura, int num){
	vector<_vertex3f> perfil;
	_vertex3f aux;

	aux.x=radio; aux.y=0; aux.z=0.0;
	perfil.push_back(aux);
	aux.x=radio; aux.y=altura; aux.z=0.0;
	perfil.push_back(aux);

	parametros(perfil,num,1,1,1);
}


// Objeto esfera (Caso especial de rotacion)

_esfera::_esfera(float radio, int num_mer, int num_par){
	vector<_vertex3f> perfil;
	_vertex3f aux;
	for(int i=1; i<num_mer; i++){
		aux.x=radio*cos(M_PI*i/(num_mer*1.0)-M_PI/2.0);
		aux.y=radio*sin(M_PI*i/(num_mer*1.0)-M_PI/2.0);
		aux.z=0.0;
		perfil.push_back(aux);
	}

	parametros(perfil,num_par,2,1,1);

}


// Objeto rotacion PLY

_rotacion_PLY::_rotacion_PLY(){

}

// Num indica el numero de lados
void _rotacion_PLY::parametros_PLY(char *archivo, int num){	
int n_ver,n_car;
int i;

vector<float> ver_ply ;
vector<int> car_ply ;
 
_file_ply::read(archivo, ver_ply, car_ply);

n_ver=ver_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

vertices.resize(n_ver);

// vertices
for(i=0; i<vertices.size(); i++){
  vertices[i].x=ver_ply[3*i];
  vertices[i].y=ver_ply[3*i+1];
  vertices[i].z=ver_ply[3*i+2];
}


// Colores
colores_caras.resize(n_car);
for(i=0; i<colores_caras.size(); i++){
  colores_caras[i].r=rand()%1000/1000.0;
  colores_caras[i].g=rand()%1000/1000.0;
  colores_caras[i].b=rand()%1000/1000.0; 
}
}
//************************************************************************
// objeto por extrusión
//************************************************************************

_extrusion::_extrusion(vector<_vertex3f> poligono, float x, float y, float z){
	int i;
	_vertex3f vertice_aux;
	_vertex3i cara_aux;
	int num_aux;

  // tratamiento de los vértice

	num_aux=poligono.size();
	vertices.resize(num_aux*2);
	for (i=0;i<num_aux;i++){
		vertices[2*i]=poligono[i];
		vertices[2*i+1].x=poligono[i].x+x;
		vertices[2*i+1].y=poligono[i].y+y;
		vertices[2*i+1].z=poligono[i].z+z;
	}
		
	// tratamiento de las caras 

	caras.resize(num_aux*2);
	int c=0;
	for (i=0;i<num_aux;i++){
		caras[c]._0=i*2;
		caras[c]._1=(i*2+2)%(num_aux*2);
		caras[c]._2=i*2+1;    
		c=c+1;

		caras[c]._0=(i*2+2)%(num_aux*2);
		caras[c]._1=(i*2+2)%(num_aux*2)+1;
		caras[c]._2=i*2+1;    
		c=c+1;    
	}   

	colores_caras.resize(2*num_aux);
	for(i=0; i<colores_caras.size(); i++){
	colores_caras[i].r=rand()%1000/1000.0;
	colores_caras[i].g=rand()%1000/1000.0;
	colores_caras[i].b=rand()%1000/1000.0; 
	}
    
}
