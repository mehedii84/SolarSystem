#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include "imageloader.h"

using namespace std;

static int slices = 16;
static int stacks = 16;

float sun = 0.0;

float MercuryOWN = 0.0;
float MercuryAroundSun = 0.0;

float VenusOWN = 0.0;
float VenusAroundSun = 0.0;

float EarthOWN = 0.0;
float EarthAroundSun = 0.0;

float MarsOWN = 0.0;
float MarsAroundSun = 0.0;

float JupiterOWN = 0.0;
float JupiterAroundSun = 0.0;

float SaturnOWN = 0.0;
float SaturnAroundSun = 0.0;

float UranusOWN = 0.0;
float UranusAroundSun = 0.0;

float NeptuneOWN = 0.0;
float NeptuneAroundSun = 0.0;




//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;

	glGenTextures(1, &textureId);
	//Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}


GLuint _textureId;

/* GLUT callback Handlers */

//Initializes 3D rendering
void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0); //Enable light #0
    glEnable(GL_LIGHT1); //Enable light #1
    glEnable(GL_NORMALIZE); //Automatically normalize normals
    glShadeModel(GL_SMOOTH); //Enable smooth shading
    //Image* image = loadBMP("G:\\amra\\text\\win.bmp");
     Image* image = loadBMP("D:\\AUST\\4.2\\Lab\\CSE 4204 - Graphics\\Project\\Solar System\\a.bmp");
	_textureId = loadTexture(image);
	delete image;

  //  glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
}


static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -10.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	//Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glColor3f(1.0f, 0.2f, 0.2f);
	glBegin(GL_QUADS);
	//glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(-80.0f, -50.0f, -85.0f);

	glTexCoord2f(1.0f, 0.0f);glVertex3f(80.0f, -50.0f, -85.0f);

	glTexCoord2f(1.0f, 1.0f);glVertex3f(80.0f, 50.0f, -85.0f);

	glTexCoord2f(0.0f, 1.0f);glVertex3f(-80.0f, 50.0f, -85.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
 glPopMatrix();

    //SUN

    glPushMatrix();
        glColor3d(1,.7,0);
        glTranslatef(0,0,-9);
        glRotatef(-65.0,1.0,0.0,0.0);
        glRotatef(sun,0.0,0.0,1.0);
        glutSolidSphere(.5,slices,stacks);
        glLoadIdentity();
    glPopMatrix();


    //MERCURY

    glPushMatrix();
        glColor3d(.8,.2,0);
        glTranslatef(0,0,-9);
        glRotatef(-65.0,1.0,0.0,0.0);
        glRotatef(MercuryAroundSun,0.0,0.0,1.0);
        glTranslatef(1.3,0.0,0.0);
        glRotatef(MercuryOWN,0.0,0.0,1.0);
        glutSolidSphere(.06,slices,stacks);
    glPopMatrix();

    //VENUS

      glPushMatrix();
        glColor3d(.7,1,0);
        glTranslatef(0,0,-9);
        glRotatef(-65.0,1.0,0.0,0.0);
        glRotatef(VenusAroundSun,0.0,0.0,1.0);
        glTranslatef(1.7,0.0,0.0);
        glRotatef(VenusOWN,0.0,0.0,1.0);
        glutSolidSphere(.11,slices,stacks);
    glPopMatrix();

    //EARTH

    glPushMatrix();
        glColor3d(0,.4,1);
        glTranslatef(0,0,-9);
        glRotatef(-65.0,1.0,0.0,0.0);
        glRotatef(EarthAroundSun,0.0,0.0,1.0);
        glTranslatef(2.2,0.0,0.0);
        glRotatef(EarthOWN,0.0,0.0,1.0);
        glutSolidSphere(.15,slices,stacks);
    glPopMatrix();

    //MARS

    glPushMatrix();
        glColor3d(1,.2,0);
        glTranslatef(0,0,-9);
        glRotatef(-65.0,1.0,0.0,0.0);
        glRotatef(MarsAroundSun,0.0,0.0,1.0);
        glTranslatef(2.7,0.0,0.0);
        glRotatef(MarsOWN,0.0,0.0,1.0);
        glutSolidSphere(.11,slices,stacks);
    glPopMatrix();

    //JUPITER

    glPushMatrix();
        glColor3d(.8,.8,0);
        glTranslatef(0,0,-9);
        glRotatef(-65.0,1.0,0.0,0.0);
        glRotatef(JupiterAroundSun,0.0,0.0,1.0);
        glTranslatef(3.3,0.0,0.0);
        glRotatef(JupiterOWN,0.0,0.0,1.0);
        glutSolidSphere(.25,slices,stacks);
    glPopMatrix();

    //SATURN

    glPushMatrix();
        glColor3d(.6,1,.7);
        glTranslatef(0,0,-9);
        glRotatef(-65.0,1.0,0.0,0.0);
        glRotatef(SaturnAroundSun,0.0,0.0,1.0);
        glTranslatef(3.9,0.0,0.0);
        glRotatef(SaturnOWN,0.0,0.0,1.0);
        glutSolidSphere(.2,slices,stacks);
    glPopMatrix();



    //URANUS


    glPushMatrix();
        glColor3d(1,1,1);
        glTranslatef(0,0,-9);
        glRotatef(-65.0,1.0,0.0,0.0);
        glRotatef(UranusAroundSun,0.0,0.0,1.0);
        glTranslatef(4.5,0.0,0.0);
        glRotatef(UranusOWN,0.0,0.0,1.0);
        glutSolidSphere(.1,slices,stacks);
    glPopMatrix();

    //NEPTUNE

    glPushMatrix();
        glColor3d(0,.8,1);
        glTranslatef(0,0,-9);
        glRotatef(-65.0,1.0,0.0,0.0);
        glRotatef(NeptuneAroundSun,0.0,0.0,1.0);
        glTranslatef(5.0,0.0,0.0);
        glRotatef(NeptuneOWN,0.0,0.0,1.0);
        glutSolidSphere(.17,slices,stacks);
    glPopMatrix();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    sun += 0.005;

	MercuryAroundSun += 0.06f;
	MercuryOWN += 0.15f;

	VenusAroundSun += 0.05f;
	VenusOWN += 0.13f;

	EarthAroundSun += 0.045f;
	EarthOWN += 0.12f;

	MarsAroundSun += 0.035f;
	MarsOWN += 0.112f;

	JupiterAroundSun += 0.032f;
	JupiterOWN += 0.111f;

	SaturnAroundSun += 0.028f;
	SaturnOWN += 0.118f;

	UranusAroundSun += 0.02f;
	UranusOWN += 0.115f;

	NeptuneAroundSun += 0.015f;
	NeptuneOWN += 0.141f;


    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1300,700);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Solar System");

        initRendering();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);



    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);




    glutMainLoop();
    return EXIT_SUCCESS;
}

