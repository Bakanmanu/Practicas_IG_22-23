//**************************************************************************
// Práctica 3 
//**************************************************************************

#include "objetos_B3.h"
#include "file_ply_stl.hpp"
#include <time.h> 


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
//**** usando vertex_array ****
glPointSize(grosor);
glColor3f(r,g,b);

glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
glDrawArrays(GL_POINTS,0,vertices.size()); 

/*int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();*/
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
//**** usando vertex_array ****
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);

glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&caras[0]);

/*int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();*/
}

//*************************************************************************
// dibujar en modo sólido con un único color
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
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
// dibujar en modo sólido con colores diferentes para cada cara
//*************************************************************************

void _triangulos3D::draw_solido_colores( )
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glColor3f(colores_caras[i].r,colores_caras[i].g,colores_caras[i].b);
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
// asignación colores
//*************************************************************************

void _triangulos3D::colors_random()
{
int i, n_c;
n_c=caras.size();
colores_caras.resize(n_c);
srand (time(NULL));
for (i=0;i<n_c;i++)  
  {colores_caras[i].r=rand()%1000/1000.0;
   colores_caras[i].g=rand()%1000/1000.0;
   colores_caras[i].b=rand()%1000/1000.0;
  }
}

//*************************************************************************

void _triangulos3D::colors_chess(float r1, float g1, float b1, float r2, float g2, float b2)
{
int i, n_c;
n_c=caras.size();
colores_caras.resize(n_c);
for (i=0;i<n_c;i++)  
  {if (i%2==0) 
     {colores_caras[i].r=r1;
      colores_caras[i].g=g1;
      colores_caras[i].b=b1;
     }
   else 
     {colores_caras[i].r=r2;
      colores_caras[i].g=g2;
      colores_caras[i].b=b2;
     } 
  }
}


//*************************************************************************
// objetos o modelos
//*************************************************************************

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
//vertices
vertices.resize(8);
vertices[0].x=-tam;vertices[0].y=-tam;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=-tam;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=tam;vertices[2].z=tam;
vertices[3].x=-tam;vertices[3].y=tam;vertices[3].z=tam;
vertices[4].x=-tam;vertices[4].y=-tam;vertices[4].z=-tam;
vertices[5].x=tam;vertices[5].y=-tam;vertices[5].z=-tam;
vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=-tam;
vertices[7].x=-tam;vertices[7].y=tam;vertices[7].z=-tam;

// triangulos
caras.resize(12);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=3;
caras[1]._0=3;caras[1]._1=1;caras[1]._2=2;
caras[2]._0=1;caras[2]._1=5;caras[2]._2=2;
caras[3]._0=5;caras[3]._1=6;caras[3]._2=2;
caras[4]._0=5;caras[4]._1=4;caras[4]._2=6;
caras[5]._0=4;caras[5]._1=7;caras[5]._2=6;
caras[6]._0=0;caras[6]._1=7;caras[6]._2=4;
caras[7]._0=0;caras[7]._1=3;caras[7]._2=7;
caras[8]._0=3;caras[8]._1=2;caras[8]._2=7;
caras[9]._0=2;caras[9]._1=6;caras[9]._2=7;
caras[10]._0=0;caras[10]._1=1;caras[10]._2=4;
caras[11]._0=1;caras[11]._1=5;caras[11]._2=4; 

//colores de las caras
colors_random();
}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{
int i;
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

//colores de las caras
colors_random();
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
int i, n_ver,n_car;

vector<float> ver_ply ;
vector<int>   car_ply ;
 
_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
n_car=car_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

vertices.resize(n_ver);
caras.resize(n_car);
// vértices

for (i=0;i<n_ver;i++)
  {vertices[i].x=ver_ply[3*i];
   vertices[i].y=ver_ply[3*i+1];
   vertices[i].z=ver_ply[3*i+2];
  }

// vértices
for (i=0;i<n_car;i++)
  {caras[i].x=car_ply[3*i];
   caras[i].y=car_ply[3*i+1];
   caras[i].z=car_ply[3*i+2];
  }

  
colores_caras.resize(n_car);
srand(10);
// colores
float sum;
int n;
colores_caras.resize(caras.size());
for (i=0;i<caras.size();i++)  
  {if (vertices[caras[i]._0].y>=0) 
     {colores_caras[i].r=rand()%1000/1000.0;
      colores_caras[i].b=0.0;
      colores_caras[i].g=0.8;
     }
   else 
      {n=rand()%10;
       sum=rand()%100/500.0;
       if (n<5) colores_caras[i].r=0.251+sum;
       else colores_caras[i].r=0.251-sum;
       if (n>5) colores_caras[i].b=0.805+sum; 
       else colores_caras[i].b=0.805-sum; 
       if (n>5) colores_caras[i].g=0.816+sum; 
       else colores_caras[i].g=0.816-sum; 
       }
   }
}


//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num, int tipo, int tapa_in, int tapa_su)
{
int i,j;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;
float radio;

// tratamiento de los vértice
radio=sqrt(perfil[0].x*perfil[0].x+perfil[0].y*perfil[0].y);

num_aux=perfil.size();
if (tipo==1) num_aux=num_aux-1;
vertices.resize(num_aux*num+2);
for (j=0;j<num;j++)
  {for (i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }

caras.resize(2*(num_aux-1)*num+2*num);
int c=0;
for (j=0;j<num;j++)
 {
  for (i=0;i<num_aux-1;i++)
    {caras[c]._0=i+j*num_aux;
     caras[c]._1=((j+1)%num)*num_aux+i;
     caras[c]._2=1+i+j*num_aux;
     c+=1;
     caras[c]._0=((j+1)%num)*num_aux+i;
     caras[c]._1=((j+1)%num)*num_aux+1+i;
     caras[c]._2=1+i+j*num_aux;
     c+=1;
   }
 }
 
 //tapa inferior
 int total=num_aux*num;
 vertices[total].x=0.0;
 if (tipo==2) vertices[total].y=-radio;
 else vertices[total].y=perfil[0].y;
 vertices[total].z=0.0;

for (j=0;j<num;j++)
 {
     caras[c]._0=j*num_aux;
     caras[c]._1=((j+1)%num)*num_aux;
     caras[c]._2=total;
     c+=1;
 } 
 
//tapa superior
 vertices[total+1].x=0.0;
 if (tipo==1) vertices[total+1].y=perfil[1].y;
 if (tipo==0) vertices[total+1].y=perfil[num_aux-1].y;
 if (tipo==2) vertices[total+1].y=radio;
 vertices[total+1].z=0.0;
 
 for (j=0;j<num;j++)
 {
     caras[c]._0=total+1;
     caras[c]._1=((j+1)%num)*num_aux+num_aux-1;
     caras[c]._2=num_aux-1+j*num_aux;
     c+=1;
 }

//colores de las caras
colors_random();
}


//************************************************************************
// objeto cilindro (caso especial de rotacion)
//************************************************************************

_cilindro::_cilindro(float radio, float altura, int num)
{
vector<_vertex3f> perfil;
_vertex3f aux;

aux.x=radio; aux.y=-altura/2.0; aux.z=0.0;
perfil.push_back(aux);
aux.x=radio; aux.y=altura/2.0; aux.z=0.0;
perfil.push_back(aux);
parametros(perfil,num,0,1,1);
}


//************************************************************************
// objeto cono (caso especial de rotacion)
//************************************************************************

_cono::_cono(float radio, float altura, int num)
{
vector<_vertex3f> perfil;
_vertex3f aux;

aux.x=radio; aux.y=0; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.0; aux.y=altura; aux.z=0.0;
perfil.push_back(aux);
parametros(perfil,num,1,1,1);
}

//************************************************************************
// objeto esfera (caso especial de rotacion)
//************************************************************************

_esfera::_esfera(float radio, int num1, int num2)
{
vector<_vertex3f> perfil;
_vertex3f aux;
int i;
for (i=1;i<num1;i++)
  {aux.x=radio*cos(M_PI*i/(num1*1.0)-M_PI/2.0);
   aux.y=radio*sin(M_PI*i/(num1*1.0)-M_PI/2.0);
   aux.z=0.0;
   perfil.push_back(aux);
  }
parametros(perfil,num2,2,1,1);
}


//************************************************************************
// rotacion archivo PLY (caso especial de rotacion)
//************************************************************************

_rotacion_PLY::_rotacion_PLY()
{

}

void _rotacion_PLY::parametros_PLY(char *archivo, int num)
{
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

//************************************************************************
// objeto por extrusión
//************************************************************************


_extrusion::_extrusion(vector<_vertex3f> poligono, float x, float y, float z)
{
int i;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=poligono.size();
vertices.resize(num_aux*2);
for (i=0;i<num_aux;i++)
    {
      vertices[2*i]=poligono[i];
      vertices[2*i+1].x=poligono[i].x+x;
      vertices[2*i+1].y=poligono[i].y+y;
      vertices[2*i+1].z=poligono[i].z+z;
    }
    
// tratamiento de las caras 

caras.resize(num_aux*2);
int c=0;
for (i=0;i<num_aux;i++)         
  {
   caras[c]._0=i*2;
   caras[c]._1=(i*2+2)%(num_aux*2);
   caras[c]._2=i*2+1;    
   c=c+1;
   caras[c]._0=(i*2+2)%(num_aux*2);
   caras[c]._1=(i*2+2)%(num_aux*2)+1;
   caras[c]._2=i*2+1;    
   c=c+1;    
   }  
   
//colores de las caras
colors_random();
}


//************************************************************************
// práctica 3, objeto jerárquico articulado
//************************************************************************

//************************************************************************
// piezas
//************************************************************************


//************************************************************************
// Tronco de Cono
//************************************************************************

_troncoCono::_troncoCono(float radio1, float radio2, float altura, int num){
  vector<_vertex3f> perfil;
  _vertex3f aux;

  aux.x=radio1; aux.y=0.0; aux.z=0.0;
  perfil.push_back(aux);
  aux.x=radio2; aux.y=altura; aux.z=0.0;
  perfil.push_back(aux);

  parametros(perfil,num,0,1,1); 
}



//************************************************************************
// Cilindro Elipse
//************************************************************************

_cilindroElipse::_cilindroElipse(float ejeP, float ejeG, float altura, int num){
  vector<_vertex3f> perfil;
  _vertex3f vertice_aux;
  _vertex3i cara_aux;
  int i, j;
  int num_aux;

  vertice_aux.x=ejeG; vertice_aux.y=-altura/2.0; vertice_aux.z=0.0;
  perfil.push_back(vertice_aux);
  vertice_aux.y=altura/2.0;
  perfil.push_back(vertice_aux);

// Tratamiento de los vertices
// Disposicion de Elipse en los vertices
  num_aux=perfil.size();
  vertices.resize(num_aux*num+2);
  for(i=0; i<num; i++){
    for(j=0; j<num_aux;j++){
      vertice_aux.x=perfil[j].x*ejeG*cos(2.0*M_PI*i/(1.0*num))+
                    perfil[j].z*ejeP*sin(2.0*M_PI*i/(1.0*num));
      vertice_aux.z=-perfil[j].x*ejeP*sin(2.0*M_PI*i/(1.0*num))+
                    perfil[j].z*ejeG*cos(2.0*M_PI*i/(1.0*num));
      vertice_aux.y=perfil[j].y;
      
      vertices[j+i*num_aux]=vertice_aux;
    }
  }

// Tratamiento de las caras

  caras.resize(2*(num_aux-1)*num+2*num);
  int c=0;
  for(j=0; j<num; j++){
    for(i=0; i<num_aux-1; i++){
      caras[c]._0=i+j*num_aux;
      caras[c]._1=((j+1)%num)*num_aux+i;
      caras[c]._2=1+i+j*num_aux;
      c+=1;
      caras[c]._0=((j+1)%num)*num_aux+i;
      caras[c]._1=((j+1)%num)*num_aux+1+i;
      caras[c]._2=1+i+j*num_aux;
      c+=1;
    }
  }

  // tapa inferior
  int total=num_aux*num;
  vertices[total].x=0.0;
  vertices[total].y=perfil[0].y;
  vertices[total].z=0.0;

  for(i=0; i<num; i++){
    caras[c]._0=i*num_aux;
    caras[c]._1=((i+1)%num)*num_aux;
    caras[c]._2=total;
    c++;
  }

  // tapa superior
  vertices[total+1].x=0.0;
  vertices[total+1].y=perfil[num_aux-1].y;
  vertices[total+1].z=0.0;

  for(i=0; i<num; i++){
    caras[c]._0=total+1;
    caras[c]._1=((i+1)%num)*num_aux+num_aux-1;
    caras[c]._2=num_aux-1+i*num_aux;
    c++;
  }

  colors_random();
}

//************************************************************************
// Esfera Elipse
//************************************************************************

_esferaElipse::_esferaElipse(float ejeP, float ejeG, int num1, int num2){
  vector<_vertex3f> perfil;
  _vertex3f vertice_aux;
  _vertex3i cara_aux;
  float radio;
  int num_aux, i, j;

//tratamiento de vertices

//Base de esfera eliptica
  for(i=1; i<num1; i++){
    vertice_aux.x=ejeP*cos(M_PI*i/(1.0*num1)-M_PI/2.0);
    vertice_aux.y=ejeG*sin(M_PI*i/(1.0*num1)-M_PI/2.0);
    vertice_aux.z=0.0;
    perfil.push_back(vertice_aux);
  }

  radio=sqrt(perfil[0].x*perfil[0].x+perfil[0].y*perfil[0].y);
// Relleno de vertices plantilla circular

  num_aux=perfil.size();
  vertices.resize(num_aux*num2+2);
  for(j=0; j<num2; j++){
    for(i=0; i<num_aux; i++){
      vertice_aux.x=perfil[i].x*ejeG*cos(2.0*M_PI*j/(1.0*num2))+
                    perfil[i].z*ejeP*sin(2.0*M_PI*j/(1.0*num2));
      vertice_aux.z=-perfil[i].x*ejeP*sin(2.0*M_PI*j/(1.0*num2))+
                    perfil[i].z*ejeG*cos(2.0*M_PI*j/(1.0*num2));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
    }
  } 

  //tratamiento de caras

  caras.resize(2*(num_aux-1)*num2+2*num2);
  int c=0;
  for(j=0; j<num2; j++){
    for(i=0; i<num_aux-1; i++){
      caras[c]._0=i+j*num_aux;
      caras[c]._1=((j+1)%num2)*num_aux+i;
      caras[c]._2=1+i+j*num_aux;
      c+=1;
      caras[c]._0=((j+1)%num2)*num_aux+i;
      caras[c]._1=((j+1)%num2)*num_aux+1+i;
      caras[c]._2=1+i+j*num_aux;
      c+=1;
    }
  }

  // tapa inferior
  int total=num_aux*num2;
  vertices[total].x=0.0;
  vertices[total].z=0.0;
  vertices[total].y=-radio;

  for (j=0;j<num2;j++){
    caras[c]._0=j*num_aux;
    caras[c]._1=((j+1)%num2)*num_aux;
    caras[c]._2=total;
    c+=1;
  } 


// tapa superior
  vertices[total+1].x=0.0;
  vertices[total+1].z=0.0;
  vertices[total+1].y=radio;

  for (j=0;j<num2;j++){
    caras[c]._0=total+1;
    caras[c]._1=((j+1)%num2)*num_aux+num_aux-1;
    caras[c]._2=num_aux-1+j*num_aux;
    c+=1;
  }

// colores random de las caras
colors_random();
}



//************************************************************************
// Pata
//************************************************************************

_pata::_pata(){
  ancho=0.2;
  alto=0.1;
  fondo=0.6;
  radio = 0.1;

};

void _pata::draw(_modo modo, float r, float g, float b, float grosor){
  // Muslo
  glPushMatrix();
    glTranslatef(0,0.27,-0.55);
    glRotatef(115,1,0,0);
    glScalef(radio, fondo, radio);
    cilindro.draw(modo,r,g,b,grosor);
  glPopMatrix();

  // Espinilla
  glPushMatrix();
    glTranslatef(0,0,-1.25);
    glRotatef(25,1,0,0);
    glScalef(radio, fondo, radio);
    cilindro.draw(modo,r,g,b,grosor);
  glPopMatrix();

  // pie
  glPushMatrix();
    glTranslatef(0,-0.55,-1.575);
    // glRotatef(25,1,0,0);
    glScalef(ancho, alto, 2*ancho);
    cubo.draw(modo,r,g,b,grosor);
  glPopMatrix();


};

//************************************************************************
// Pinza
//************************************************************************
_pinza::_pinza(){
  ancho=0.35;
  alto=0.3;
  fondo=0.3;
  cilindro = _cilindro(1.0,2.0,3);
  cono = _cono(1.0,2.0,3);

}


void _pinza::draw(_modo modo, float r, float g, float b, float grosor){
  // Base de la pinza
  glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(ancho*2, alto*2, fondo*2);
    elipse3d.draw(modo,r,g,b,grosor);
  glPopMatrix();

  // Pinza1
  glPushMatrix();
    glTranslatef(-fondo-0.05,0,0.55);
    glRotatef(90,1,0,0);
    glScalef(fondo/2.0, alto, fondo/2.0);
    cilindro.draw(modo,r,g,b,grosor);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-fondo-0.05,0,0.8);
    glRotatef(90,1,0,0);
    glRotatef(-30,0,0,1);
    glScalef(fondo/2.0, alto, fondo/2.0);
    cono.draw(modo,r,g,b,grosor);
  glPopMatrix();
  
  // Pinza2
  glPushMatrix();
    glTranslatef(fondo+0.05,0,0.55);
    glRotatef(90,1,0,0);
    glRotatef(180,0,0,1);
    glScalef(fondo/2.0, alto, fondo/2.0);
    cilindro.draw(modo,r,g,b,grosor);
  glPopMatrix();
  
  glPushMatrix();
    glTranslatef(fondo+0.05,0,0.8);
    glRotatef(90,1,0,0);
    glRotatef(180,0,1,0);
    glRotatef(-30,0,0,1);
    glScalef(fondo/2.0, alto, fondo/2.0);
    cono.draw(modo,r,g,b,grosor);
  glPopMatrix();
}


//************************************************************************
// Brazo
//************************************************************************
_brazo::_brazo(){
  ancho=0.3;
  alto=0.6;
  fondo=0.25;

}

void _brazo::draw(_modo modo, float r, float g, float b, float grosor){
  // Brazo 1
  glPushMatrix();
    glScalef(ancho, alto, fondo);
    cilindro.draw(modo,r,g,b,grosor);
  glPopMatrix();
  
  // Brazo 2
  glPushMatrix();
    glTranslatef(-0.15,alto*1.5,0);
    glRotatef(20,0,0,1);
    glScalef(ancho, alto*3/4, fondo);
    cilindro.draw(modo,r,g,b,grosor);
  glPopMatrix();
  
  // Pinza
  glPushMatrix();
    glTranslatef(-0.45,1.7,0);
    glRotatef(-90,1,0,0);
    glRotatef(-20,0,1,0);
    pinza.draw(modo,r,g,b,grosor);
  glPopMatrix();
}

//************************************************************************
// Aguijon
//************************************************************************
_aguijon::_aguijon(){
  ancho=1.0;
  alto=1.0;
  fondo=0.5;

}

void _aguijon::draw(_modo modo, float r, float g, float b, float grosor){
  glPushMatrix();
    glScalef(ancho, alto, ancho*1.3);
    esfera.draw(modo,r,g,b,grosor);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0,0.85,0);
    glScalef(fondo, alto/2, fondo*1.3);
    cono.draw(modo,r,g,b,grosor);
  glPopMatrix();

}

//************************************************************************
// Cola
//************************************************************************
_cola::_cola(){
  ancho=1.0;
  alto=1.0;
  fondo=0.5;

}

void _cola::draw(_modo modo, float r, float g, float b, float grosor){
  // base de la cola (conecta con el cuerpo)
  glPushMatrix();
    // glTranslatef(0,0,0);
    glRotatef(45,1,0,0);
    glScalef(1,1.25,0.75);
    tronco.draw(modo,r,g,b,grosor);
  glPopMatrix();

// Eslabones de la cola
  glPushMatrix();

  glPopMatrix();



// Aguijon
  glPushMatrix();

  glPopMatrix();

}



//************************************************************************
// Escorpion
//************************************************************************
_escorpion::_escorpion(){
  ancho=1.0;
  alto=2.0;
  fondo=0.8;

  giro_brazo1 = 15.0;
  giro_cola = 45.0;
  giro_patas = 20.0;


  giro_brazo_max=45.0;
  giro_brazo_min=15.0;
  giro_cola_max=45.0;
  giro_cola_min=0.0;
  giro_patas_max=45.0;
  giro_patas_min=0.0;

}

void _escorpion::draw(_modo modo, float r, float g, float b, float grosor){
  glPushMatrix();
  // ***** CUERPO ***** //
    glRotatef(90,1,0,0);
    glScalef(ancho, alto, fondo);
    cuerpo.draw(modo, r, g, b, grosor);
  glPopMatrix();

  // ***** CABEZA ***** //
  glPushMatrix();
    glTranslatef(0,0,3);
    glRotatef(90,0,0,1);
    glRotatef(90,0,1,0);
    glScalef(ancho, 1, fondo);
    elipse3d.draw(modo,r,g,b,grosor);
  glPopMatrix();    
  

  // ***** BRAZOS ***** //
  // izq
  glPushMatrix();
    glTranslatef(1,0,3);
    glRotatef(90,1,0,0);
    glRotatef(-giro_brazo1,0,0,1);
    glScalef(0.6,0.6,0.6);
    brazo.draw(modo,r,g,b,grosor);
  glPopMatrix();

  //der
  glPushMatrix();
    glTranslatef(-1,0,3);
    glRotatef(90,1,0,0);
    glRotatef(180,0,1,0);
    glRotatef(-giro_brazo1,0,0,1);
    glScalef(0.6,0.6,0.6);
    brazo.draw(modo,r,g,b,grosor);
  glPopMatrix();




  // ***** PATAS ***** //
  // Lado Izq
  glPushMatrix();
    glTranslatef(ancho*3.0/4.0, 0, -1.5);
    glRotatef(-90,0,1,0);
    // glRotatef(-90,1,0,0);
    // glScalef(1, 1, 1);
    glRotatef(giro_patas,0,1,0);
    pata.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPushMatrix();  
    glTranslatef(ancho*3.0/4.0, 0, 0);
    glRotatef(-90,0,1,0);
    glRotatef(giro_patas,0,1,0);
    pata.draw(modo, r, g, b, grosor);
  glPopMatrix();
  
  glPushMatrix();
    glTranslatef(ancho*3.0/4.0, 0, 1.5);
    glRotatef(-90,0,1,0);
    glRotatef(giro_patas,0,1,0);
    pata.draw(modo, r, g, b, grosor);
  glPopMatrix();
  
  // Lado Der
  glPushMatrix();
    glTranslatef(-ancho*3.0/4.0, 0, -1.5);
    glRotatef(90,0,1,0);
    glRotatef(giro_patas,0,1,0);
    pata.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPushMatrix();  
    glTranslatef(-ancho*3.0/4.0, 0, 0);
    glRotatef(90,0,1,0);
    glRotatef(giro_patas,0,1,0);
    pata.draw(modo, r, g, b, grosor);
  glPopMatrix();
  
  glPushMatrix();
    glTranslatef(-ancho*3.0/4.0, 0, 1.5);
    glRotatef(90,0,1,0);
    glRotatef(giro_patas,0,1,0);
    pata.draw(modo, r, g, b, grosor);
  glPopMatrix();
  

  // ***** COLA ***** //
  glPushMatrix();

  
  
  glPopMatrix();




};