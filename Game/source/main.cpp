#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

GLfloat angle, fAspect;
GLfloat Superficie[3]={0.6,0.3,0};
GLint pcamera[3]={0,100,400};
GLfloat vrot[2]={0.1,0.1};
GLfloat tet=0;
GLfloat tetstep=5;
GLfloat fcam[3]={0,0,0};
GLint contcam=0;
GLint saque=0;
GLint ptp1=0, ptp2=0;
GLint pluz[4]={0,100,0,0};
char texto[30]="Teste", aviso[38]="Para iniciar outra partida aperte 'J'";
GLint winw,winh;
int sorteio,ajuda=0;
GLfloat especularidade[4]={0.0,0.0,0.0,1.0}; 
int fimdeturno=0;
int Pausa = 0;
float mi=0.1;

void Inicializa(void);
void EspecificaParametrosVisualizacao(void);

typedef struct Bola{

	GLfloat Massa;
	GLfloat Aceleracao[2];
	GLfloat Velocidade[2];
	GLfloat Posicao[2];
	GLfloat Cor[3];
	GLfloat VelocidadeTotal;
} Bola;

typedef struct Raquete{
	GLfloat Massa;
	GLfloat Aceleracao[2];
	GLfloat Velocidade[2];
	GLfloat Posicao[3];
	GLfloat Cor[3];
}Raquete;

Raquete R1,R2;
Bola bola;

// Função callback chamada para fazer o desenho
void DesenhaPlacar() 
{   
  	glPushMatrix();
	glDisable(GL_LIGHTING);
  	if(winh == 0) winh = 1; 
                            
                   // Especifica as dimensões da Viewport 
                   glViewport(0, 0, winw, winh); 
 
                   // Inicializa o sistema de coordenadas 
                   glMatrixMode(GL_PROJECTION); 
                   glLoadIdentity(); 
 
                   // Estabelece a janela de seleção (left, right, bottom, top) 
                   if (winw <= winh)  
                           gluOrtho2D (600.0f, 0.0f, 600.0f, 0.0f); 
                   else  
                           gluOrtho2D (0.0f, 600.0f, 0.0f, 600.0f);
  	
  	glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();
  	glColor3f(1,1,0);
	
	if(!ajuda){
		char* string1 = "ESC - Sair     F1 - Ajuda"; 
	
	glRasterPos2f(0,winh-10);
	while(*string1)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string1++);
	}
	
	//Placar do jogador 1
	
	if(ptp1!=6&&ptp1!=5){
	glTranslatef(450,500,0);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
	if(ptp1!=2){
	glTranslatef(450,475,0);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
	if(ptp1==0||ptp1==4||ptp1==5||ptp1==6||ptp1==8||ptp1==9){
	glTranslatef(425,500,0);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
	if(ptp1==0||ptp1==2||ptp1==6||ptp1==8){
	glTranslatef(425,475,0);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
	if(ptp1==0||ptp1==2||ptp1==3||ptp1==5||ptp1==6||ptp1==7||ptp1==8||ptp1==9){
	glTranslatef(437.5,515,0);
	glRotatef(90,0,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
	if(ptp1==0||ptp1==2||ptp1==3||ptp1==5||ptp1==6||ptp1==8||ptp1==9){
	glTranslatef(437.5,460,0);
	glRotatef(90,0,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
	if((ptp1>=2&&ptp1<=6)||ptp1==8||ptp1==9){
	glTranslatef(437.5,486.5,0);
	glRotatef(90,0,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
//Desenha placar 2
if(ptp2!=6&&ptp2!=5){
	glTranslatef(150,500,0);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
	if(ptp2!=2){
	glTranslatef(150,475,0);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
	if(ptp2==0||ptp2==4||ptp2==5||ptp2==6||ptp2==8||ptp2==9){
	glTranslatef(125,500,0);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
	if(ptp2==0||ptp2==2||ptp2==6||ptp2==8){
	glTranslatef(125,475,0);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
	if(ptp2==0||ptp2==2||ptp2==3||ptp2==5||ptp2==6||ptp2==7||ptp2==8||ptp2==9){
	glTranslatef(137.5,515,0);
	glRotatef(90,0,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
	if(ptp2==0||ptp2==2||ptp2==3||ptp2==5||ptp2==6||ptp2==8||ptp2==9){
	glTranslatef(137.5,460,0);
	glRotatef(90,0,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
	if((ptp2>=2&&ptp2<=6)||ptp2==8||ptp2==9){
	glTranslatef(137.5,486.5,0);
	glRotatef(90,0,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,10);
		glVertex2f(2.5,-10);
		glVertex2f(1.5,-11.5);
		glVertex2f(-1.5,-11.5);
		glVertex2f(-2.5,-10);
		glVertex2f(-2.5,10);
		glVertex2f(-1.5,11.5);
		glVertex2f(1.5,11.5);
	glEnd();
	glLoadIdentity();
}
        // Posição no universo onde o texto será colocado          
        /*
        glRasterPos2f(0,0); 
        
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string++);
             */ 
    glEnable(GL_LIGHTING);
	glPopMatrix();
}

void Ajuda();

void FimdeTurno(char *string1,char *string2){
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  	if(winh == 0) winh = 1; 
                            
                   // Especifica as dimensões da Viewport 
    glViewport(0, 0, winw, winh); 
 
                   // Inicializa o sistema de coordenadas 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
 
                   // Estabelece a janela de seleção (left, right, bottom, top) 
    gluOrtho2D (0,winw, 0.0f, winh); 
          
  	
  	glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();
  	
  	glColor4f(0,0,0,1);
	
	glRasterPos2f(winw/2-50,winh/2);
	
	while(*string1)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string1++);
             
    glRasterPos2f(winw/2-72,winh/2-10);
	
	while(*string2)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string2++);
  	
  	glColor4f(1,1,1,0.7);
	
	glBegin(GL_QUADS);
		glVertex2f(winw/2-90,winh/2-40);
		glVertex2f(winw/2+90,winh/2-40);
		glVertex2f(winw/2+90,winh/2+40);
		glVertex2f(winw/2-90,winh/2+40);
	glEnd();
  	
  	glColor4f(1,0,0,0.7);
  	
  	glBegin(GL_QUADS);
		glVertex2f(winw/2-100,winh/2-50);
		glVertex2f(winw/2+100,winh/2-50);
		glVertex2f(winw/2+100,winh/2+50);
		glVertex2f(winw/2-100,winh/2+50);
	glEnd();
	
	
	
    
	
	glEnable(GL_LIGHTING);
	glPopMatrix();
	
}

void Desenha(void)
{
	
	
	
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	EspecificaParametrosVisualizacao();
	
    glColor3f(Superficie[0], Superficie[1], Superficie[2]);

    glBegin(GL_QUADS);
        glVertex3f(100,0,200);
        glVertex3f(-100,0,200);
        glVertex3f(-100,0,-200);
        glVertex3f(100,0,-200);
    glEnd();
	
    glColor3f(1,1,1);
	
	
    glBegin(GL_QUADS);
        glVertex3f(100,0.1,10);
        glVertex3f(100,0.1,-10);
        glVertex3f(-100,0.1,-10);
        glVertex3f(-100,0.1,10);
    glEnd();
	
    glColor3f(1,1,1);
	
    glPushMatrix();
    glTranslatef(105,15,0);
    glScalef(0.025,0.075,1.0);
    glutSolidCube(400);
    glPopMatrix();
	
    glPushMatrix();
    glTranslatef(-105,15,0);
    glScalef(0.025,0.075,1.0);
    glutSolidCube(400);
    glPopMatrix();
	
    glPushMatrix();
    glTranslatef(0,25,-195);
    glScalef(1.0,0.05,0.05);
    glutSolidCube(200);
    glPopMatrix();
	
    glPushMatrix();
    glTranslatef(0,25,195);
    glScalef(1.0,0.05,0.05);
    glutSolidCube(200);
    glPopMatrix();

	glColor3f(R1.Cor[0],R1.Cor[1],R1.Cor[2]);
	glPushMatrix();
	//glTranslatef(praq1[0],praq1[1],praq1[2]);
	//Desenha Raquete 1 em z=-180
	
	glPushMatrix();
	glTranslatef(R1.Posicao[0],R1.Posicao[1],R1.Posicao[2]);
	glScalef(2.0,1,0.25);
	glutSolidCube(20);
	glPopMatrix();
	//Desenha raquete 2 em z = +180
		
	glPushMatrix();
	glTranslatef(R2.Posicao[0],R2.Posicao[1],R2.Posicao[2]);
	glScalef(2.0,1,0.25);
	glutSolidCube(20);
	glPopMatrix();

	glColor3f(bola.Cor[0],bola.Cor[1],bola.Cor[2]);
	
	glPushMatrix();
	especularidade[0]=1;
	especularidade[1]=1;
	especularidade[2]=1;
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	glTranslatef(bola.Posicao[0],10,bola.Posicao[1]);
	glRotatef(tet,vrot[1],0,vrot[0]);
	glutSolidSphere(10,25,25);
	glPopMatrix();
	
	especularidade[0]=0;
	especularidade[1]=0;
	especularidade[2]=0;
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);

	DesenhaPlacar();
	if(ptp1==9||ptp2==9){
	if(ptp1==9)
		sprintf(texto,"Jogador 1 ganhou o jogo");
	else sprintf(texto,"Jogador 2 ganhou o jogo");
		FimdeTurno(texto,aviso);
	}
	if(ajuda)Ajuda();
	// Executa os comandos OpenGL
	glutSwapBuffers();
 }

// Inicializa parâmetros de rendering
void Inicializa (void)
{ GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.5,0.5,0.5,1.0};	   // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
    GLfloat posicaoLuz[4]={float(pluz[0]), float(pluz[1]), float(pluz[2]), float(pluz[3])};

	// Capacidade de brilho do material
	
	GLint especMaterial = 30;

 	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
	
	
	
    angle=45;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	glClear(GL_DEPTH_BUFFER_BIT);
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
	gluPerspective(angle,fAspect,0.1,800);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	gluLookAt(pcamera[0],pcamera[1],pcamera[2], fcam[0],fcam[1],fcam[2], 0,1,0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;
	
	winw=w;
	winh=h;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse

void MenuSuperficie(int v){
	switch(v){
		case 0: mi = 0.05; Superficie[0] = 0.7; Superficie[1] = 0.7; Superficie[2] = 1;  break;
		case 1: mi = 0.1; Superficie[0] = 0.5; Superficie[1] = 0.5; Superficie[2] = 0; break;
		case 2: mi = 0.2; Superficie[0] = 0; Superficie[1] = 0.5; Superficie[2] = 0;break;
	}
	
}

void MenuBola(int v){
	switch(v){
		case 0: bola.Massa = 1; bola.Cor[0] = 0; bola.Cor[1] = 0.2; bola.Cor[2] = 1; break;
		case 1: bola.Massa = 1.5; bola.Cor[0] = 0.3; bola.Cor[1] = 0.3; bola.Cor[2] = 0; break;
		case 2: bola.Massa = 2; bola.Cor[0] = 0.5; bola.Cor[1] = 0.5; bola.Cor[2] = 0.5; break;
	}
	
}

void MenuRaquetes(int v){
	switch(v){
       case 0: R1.Massa = 1; R1.Cor[0] = 0; R1.Cor[1] = 0; R1.Cor[2] = 1; R2.Massa = 1; R2.Cor[0] = 0; R2.Cor[1] = 0; R2.Cor[2] = 1; break;
       case 1: R1.Massa = 1.5; R1.Cor[0] = 0.5; R1.Cor[1] = 0.5; R1.Cor[2] = 0; R2.Massa = 1.5; break;
       case 2: R1.Massa = 2; R1.Cor[0] = 0.5; R1.Cor[1] = 0.5; R1.Cor[2] = 0.5; R2.Massa = 2; break;
              
    }
}

void MenuPrincipal(int i=0){
	
	int menu,submenu1,submenu2,submenu3;
	

    submenu1 = glutCreateMenu(MenuSuperficie);
    glutAddMenuEntry("Gelo",0);
    glutAddMenuEntry("Madeira",1);
    glutAddMenuEntry("Sinuca",2);
    
	submenu2 = glutCreateMenu(MenuBola);
	glutAddMenuEntry("Borracha", 0);
	glutAddMenuEntry("Madeira", 1);
	glutAddMenuEntry("Metal", 2);
	
	
	submenu3 = glutCreateMenu(MenuRaquetes);
	glutAddMenuEntry("Borracha", 0);
	glutAddMenuEntry("Madeira", 1);
	glutAddMenuEntry("Metal", 2);
	
	
    menu = glutCreateMenu(MenuPrincipal);
    glutAddSubMenu("Superficie",submenu1);
    glutAddSubMenu("Bola",submenu2);
    glutAddSubMenu("Raquetes", submenu3);

	glutAttachMenu(GLUT_LEFT_BUTTON);
	glutPostRedisplay();
	
}

void GerenciaMouse(int button, int state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON)
		if(state==GLUT_DOWN)
            MenuPrincipal();
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void Time(int value){

  if(!fimdeturno && !Pausa && !ajuda){

	//modulo da aceleracao do atrito
	float atc = mi*9.8;
	
	//atualiza a velocidade
	if(bola.Velocidade[1]>0)
	bola.Velocidade[1]-=atc;
	if(bola.Velocidade[1]<0)
	bola.Velocidade[1]+=atc;
	if(bola.Velocidade[0]>0)
	bola.Velocidade[0]-=atc;
	if(bola.Velocidade[0]<0)
	bola.Velocidade[0]+=atc;
	
	
	bola.VelocidadeTotal = sqrt(bola.Velocidade[1]*bola.Velocidade[1]+bola.Velocidade[0]*bola.Velocidade[0]);
	
		
	//atualiza a posicao da bola
	bola.Posicao[0]+=bola.Velocidade[0];
	bola.Posicao[1]+=bola.Velocidade[1];
	tet+=tetstep;
	
	//calcula rotacao
	float mod;
	if(bola.Velocidade[0]!=0||bola.Velocidade[1]!=0){
	mod= sqrt(bola.Velocidade[0]*bola.Velocidade[0]+bola.Velocidade[1]*bola.Velocidade[1]);
	vrot[0]=bola.Velocidade[0]/mod;
	vrot[1]=bola.Velocidade[1]/mod;
}
	//colisao com as paredes
	if(bola.Posicao[0]>90){
		bola.Velocidade[0]=-bola.Velocidade[0];
		bola.Posicao[0]=90;
	}
	
	if(bola.Posicao[0]<-90){
		
		bola.Velocidade[0]=-bola.Velocidade[0];
		bola.Posicao[0]=-90;
	}
	
	//controla o foco da camera quando o modo de camera 4 esta acionado
	if(contcam){
		fcam[0]=bola.Posicao[0];
		fcam[1]=10;
		fcam[2]=bola.Posicao[1];
		
	}
	
	else{
		fcam[0]=0;
		fcam[1]=0;
		fcam[2]=0;
	}
	
	//Colisao da bola com a raquete R1
	if((bola.Posicao[1]<R1.Posicao[2]+11 && bola.Posicao[1]>R1.Posicao[2]-41)&& bola.Posicao[0]>R1.Posicao[0]-30 && bola.Posicao[0]<R1.Posicao[0]+30 ){
        float an = acos(-bola.Velocidade[1]/bola.VelocidadeTotal);
		bola.Velocidade[1] = bola.VelocidadeTotal*cos(an);
		bola.Velocidade[0] = bola.VelocidadeTotal*sin(an);
		
		if(bola.VelocidadeTotal < 22){
        float i0,i1;
        i0=(5/bola.Massa+bola.Velocidade[0]);
		i1 = (5/bola.Massa+bola.Velocidade[1]);
        bola.Velocidade[1]+=i1;
        if(bola.Velocidade[0]>0)
		bola.Velocidade[0]+=i0;
		if(bola.Velocidade[0]<0)
		bola.Velocidade[0]-=i0;
		bola.VelocidadeTotal-=sqrt(i1*i1+i0*i0);
        }
        else{
			float an = acos(bola.Velocidade[1]/bola.VelocidadeTotal);
			bola.Velocidade[1] = 22*cos(an);
			bola.Velocidade[0] = 22*sin(an);
			bola.VelocidadeTotal = 22;
		}
		bola.Posicao[1]=R1.Posicao[2]+10;
		
		tet=-tet;
		if(contcam){
			pcamera[0]=bola.Posicao[0];
		    pcamera[1]=30;
		    pcamera[2]=bola.Posicao[1];
	}
		
	}
	
	//Colisao com a raquete R2
	if((bola.Posicao[1]>R2.Posicao[2]-11 && bola.Posicao[1]<R2.Posicao[2]+41) && bola.Posicao[0]>R2.Posicao[0]-30 && bola.Posicao[0]<R2.Posicao[0]+30){
		
        float an = acos(-bola.Velocidade[1]/bola.VelocidadeTotal);
		bola.Velocidade[1] = bola.VelocidadeTotal*cos(an);
		bola.Velocidade[0] = bola.VelocidadeTotal*sin(an);
        if(bola.VelocidadeTotal<22){
        float i0,i1;
        i0=(5/bola.Massa+bola.Velocidade[0]);
		i1 = (5/bola.Massa+bola.Velocidade[1]);
        bola.Velocidade[1]+=i1;
        if(bola.Velocidade[0]>0)
		bola.Velocidade[0]+=i0;
		if(bola.Velocidade[0]<0)
		bola.Velocidade[0]-=i0;
		bola.VelocidadeTotal+=sqrt(i1*i1+i0*i0); 
        }
        else{
			float an = acos(bola.Velocidade[1]/bola.VelocidadeTotal);
			bola.Velocidade[1] = 22*cos(an);
			bola.Velocidade[0] = 22*sin(an);
			bola.VelocidadeTotal = 22;
		}
       
		bola.Posicao[1]=R2.Posicao[2]-11;
		tet=-tet;
		if(contcam){
			pcamera[0]=bola.Posicao[0];
		    pcamera[1]=30;
		    pcamera[2]=bola.Posicao[1];
	}
	
	}
	
	
	
	
	
	//Faz a bola acompanhar a raquete que ira sacar
	if(bola.Posicao[1]==R2.Posicao[2]-11&&saque) bola.Posicao[0]=R2.Posicao[0];
	if(bola.Posicao[1]==R1.Posicao[2]+11&&saque) bola.Posicao[0]=R1.Posicao[0];
	
	//controle de pontos quando a bola para
	if(bola.Velocidade[1]>=-atc&&bola.Velocidade[1]<=atc&&bola.Velocidade[0]<=atc&&bola.Velocidade[0]>=-atc&&!saque){
		if(bola.Posicao[1]>0){
			ptp2++;
			bola.Velocidade[1]=0;
			bola.Velocidade[0]=0;
			bola.Aceleracao[1]=0;
			bola.Aceleracao[0]=0;
			bola.Posicao[1]=R1.Posicao[2]+11;
			bola.Posicao[0]=R1.Posicao[0];
			saque=1;
		}
		else{
			ptp1++;
			bola.Velocidade[1]=0;
			bola.Velocidade[0]=0;
			bola.Aceleracao[1]=0;
			bola.Aceleracao[0]=0;
			bola.Posicao[1]=R2.Posicao[2]-11;
			bola.Posicao[0]=R2.Posicao[0];
			saque=1;
		}
	}
	
	//Ponto por passagem do fundo
	if(bola.Posicao[1]>210||bola.Posicao[1]<-210){
		bola.Velocidade[0]=0;
		bola.Velocidade[1]=0;
		bola.Aceleracao[0]=0;
		bola.Aceleracao[1]=0;
		saque=1;
	}
	//controle de pontos por passagem do fundo
	if(bola.Posicao[1]>210){
		bola.Posicao[0]=R1.Posicao[0];
		bola.Posicao[1]=R1.Posicao[2]+11;
		ptp2++;
		
	}
	
	if(bola.Posicao[1]<-210){
		bola.Posicao[0]=R2.Posicao[0];
		bola.Posicao[1]=R2.Posicao[2]-11;
		ptp1++;
	}
	
	//relata fim de turno
	if(ptp1==9||ptp2==9)
		fimdeturno=1;
	
}	
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
    glutTimerFunc(33,Time, 1);
}


void Teclado(unsigned char key, int x, int y){
  if(!fimdeturno && !Pausa && !ajuda){
	switch(key){
		case '1': pcamera[0]=0; 
				  pcamera[1]=100;
				  pcamera[2]=400;
				  contcam=0;
				  break;
		case '2': pcamera[0]=-400;
				  pcamera[1]=200;
				  pcamera[2]=0;
				  contcam=0;
				  break;
		case '3': pcamera[0]=0;
				  pcamera[1]=465;
				  pcamera[2]=1;
				  contcam=0;
				  break;
		case '4': contcam=1;
				fcam[0]=bola.Posicao[0];
				fcam[1]=10;
				fcam[2]=bola.Posicao[1];
				pcamera[0]=bola.Posicao[0]-30;
				pcamera[1]=20;
				pcamera[2]=bola.Posicao[1]-30;
				  break;
        case '5':pcamera[0] = 400;
                 pcamera[1] = 200;
                 pcamera[2] = 400;
                 contcam = 0;
                 break;
             
             
		case 'q': R1.Posicao[0]-=20; break;
		case 'e': R1.Posicao[0]+=20; break;
		
		
		
		
		
	}
	
	if(R1.Posicao[0]>70)
		R1.Posicao[0]=70;
	if(R1.Posicao[0]<-70)
		R1.Posicao[0]=-70;
	if(key=='t'&&saque&&bola.Posicao[1]==R1.Posicao[2]+11){
        float an;                                                   
		bola.Velocidade[0]=0;
		an = M_PI*(rand()%81+55)/180;
		bola.Velocidade[1]=30*sin(an)*R1.Massa/bola.Massa;
		saque=0;

		bola.Velocidade[0]=30*cos(an)*R1.Massa/bola.Massa;
		bola.VelocidadeTotal = 30*R1.Massa/bola.Massa;
	}
}
else{
	if((key=='j'||key=='J')&&fimdeturno){
	ptp2=0;
	ptp1=0;
	fimdeturno=0;
}
}
	if(key == ' '){
		if(Pausa) Pausa = 0; 
		else Pausa = 1;
	}
	if(key==27)
	exit(1);
	
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}
void Ajuda(){
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  	if(winh == 0) winh = 1; 
                            
                   // Especifica as dimensões da Viewport 
    glViewport(0, 0, winw, winh); 
 
                   // Inicializa o sistema de coordenadas 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
 
                   // Estabelece a janela de seleção (left, right, bottom, top) 
    gluOrtho2D (0,winw, 0.0f, winh); 
          
  	
  	glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();
  	glColor3f(1,1,0);
	char* string1 = "Q e E movem a raquete 1";
	char* string2 = "As setas Direita e Esquerda movem a raquete 2";
	char* string3 = "T -  saca com a raquete 1";
	char* string4 = "END - saca com a raquete 2";
	char* string5 = "1 2 3 4 5 - Posicoes de camera";
	char* string6 = "ESC - Encerra o jogo";
	char* string7 = "SPACE - pausa o jogo"; 
	
	glRasterPos2f(winw/2-50,winh/2+90);
	while(*string1)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string1++);
             
    glRasterPos2f(winw/2-50,winh/2+60);
	while(*string2)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string2++);
          
    glRasterPos2f(winw/2-50,winh/2+30);
	while(*string3)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string3++);
             
    glRasterPos2f(winw/2-50,winh/2);
	while(*string4)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string4++);
    
    glRasterPos2f(winw/2-50,winh/2-30);
    while(*string5)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string5++); 
             
    glRasterPos2f(winw/2-50,winh/2-60);
    while(*string6)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string6++); 
    
    glRasterPos2f(winw/2-50,winh/2-90);
    while(*string7)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string7++);      
             
    glEnable(GL_LIGHTING);      
	glPopMatrix();
}
void Especial(int key, int x, int y){
  if(!fimdeturno && !Pausa && !ajuda){
	switch(key){
		case GLUT_KEY_LEFT : R2.Posicao[0]-=20;
							 if(contcam) R2.Posicao[0]+=40;
							 break;
		case GLUT_KEY_RIGHT : R2.Posicao[0]+=20;
							  if(contcam) R2.Posicao[0]-=40;
							  break;
	}
	if(R2.Posicao[0]>70)
		R2.Posicao[0]=70;
	if(R2.Posicao[0]<-70)
		R2.Posicao[0]=-70;
	if(key==GLUT_KEY_END&&saque&&bola.Posicao[1]==R2.Posicao[2]-11){
        float an;                                                            
		bola.Velocidade[0]=0;
		saque=0;
		an = M_PI*(rand()%81+55)/180;
		bola.Velocidade[1]=-30*sin(an)*R2.Massa/bola.Massa;
		bola.Velocidade[0]=30*cos(an)*R2.Massa/bola.Massa;
		bola.VelocidadeTotal = 30*R2.Massa/bola.Massa;
	}
	
}
	if(key==GLUT_KEY_F1){
		if(ajuda) ajuda = 0;
		else ajuda =1;
	}
	
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}  

// Programa Principal
int main(int argc, char* args[])
{	
	bola.Massa = 1;
    bola.Cor[0] = 0; 
    bola.Cor[1] = 0.2; 
    bola.Cor[2] = 1;
	R1.Posicao[0] = 0;
	R1.Posicao[1] = 10;
	R1.Posicao[2] = -182.5;
	R1.Massa = 1;
	R1.Cor[0] = 0;
	R1.Cor[1] = 0;
	R1.Cor[2] = 1;
	R2.Massa = 1;
	R2.Posicao[0] = 0;
	R2.Posicao[1] = 10;
	R2.Posicao[2] = 182.5;
	mi = 0.05;
	Superficie[0] = 0.7;
	Superficie[1] = 0.7;
	Superficie[2] = 1;
	
	
	srand(time(NULL));
	sorteio=rand()%2;
	if(sorteio==1){
		bola.Posicao[0]=R1.Posicao[0];
		bola.Posicao[1]=R1.Posicao[2]+11;
		
	}
	else{
		bola.Posicao[0]=R2.Posicao[0];
		bola.Posicao[1]=R2.Posicao[2]-11;
	}
	saque=1;
	
	glutInit(&argc, args);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1024,600);
	glutCreateWindow("Pong");
	glutFullScreen();
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(Teclado);
	glutSpecialFunc(Especial);
	glutTimerFunc(33,Time,1);
	Inicializa();
	glutMainLoop();
    return 0;
}
