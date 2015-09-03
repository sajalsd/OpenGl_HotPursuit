#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<GL/glut.h>

double cameraAngle, cameraAngleDelta;
int canDrawGrid;

double cameraHeight;	
double cameraRadius;

double carcentrex=0,carcentrey=0,carcentrez=0;	//for moving whole shape
double speed=.5;

void wheel(int i, int j, int k)
{
		
		glTranslatef(i,j,k);	
		glRotatef(90,1,0,0);
		
		GLUquadricObj *quadric;
		quadric = gluNewQuadric();
		for(int i=8;i>0; i= i-.00001)
		{
			if(i>4)
				glColor3f(.2,.2,.2);
			else
				glColor3f(.75,.79,.5);
			//(pointer,base radius,top radius,height, slice,stack)
			gluCylinder(quadric,i,i,5,60,60);
		}
		
}


void car(double y){

	glTranslatef(0,y,0);
	glPushMatrix();
	{
		glRotatef(90,0,0,1);
		glTranslatef(0,0,10);
		glScalef(.5,.5,.3);
		glPushMatrix();
		{
			//main base
			glPushMatrix();
			{	
				glColor3f(.5,0,0);
				glScalef(2,1,1);
				glutSolidCube(40);
		
		
			}glPopMatrix();

			//wheel
			glPushMatrix();
			{	
				wheel(52,-18,-16);
		
			}glPopMatrix();
			//wheel
			glPushMatrix();
			{	
				wheel(-30,-18,-16);
		
			}glPopMatrix();
			//wheel
			glPushMatrix();
			{	
				wheel(52,23,-16);
		
			}glPopMatrix();
			//wheel
			glPushMatrix();
			{	
				wheel(-30,23,-16);
		
			}glPopMatrix();

			//front(engin) cube

			glPushMatrix();
			{	
		
				glColor3f(.5,0,0);
				glTranslatef(55,0,-10);
				glScalef(1.3,1,.5);
				glutSolidCube(40);
		
		
			}glPopMatrix();

			//front(engin) support(tringle)
			glPushMatrix();
			{	
		
				glColor3f(.5,0,0);
				glTranslatef(40,-20,0);
				glBegin(GL_TRIANGLES);{
					glVertex3f(0,0,0);
					glVertex3f(15,0,0);
					glVertex3f(0,0,20);
				}glEnd();
			
			}glPopMatrix();

			//front(engin) support(tringle)
			glPushMatrix();
			{	
		
				glColor3f(.5,0,0);
				glTranslatef(40,20,0);
				glBegin(GL_TRIANGLES);{
					glVertex3f(0,0,0);
					glVertex3f(15,0,0);
					glVertex3f(0,0,20);
				}glEnd();
			
			}glPopMatrix();
			//front glass
			glPushMatrix();
			{	
		
				glColor4f(.1,.1,.1,0.8);
				glTranslatef(55,0,0);
				glRotated(-35,0,1,0);
				glBegin(GL_QUADS);{
					glVertex3f(0,17,0);
					glVertex3f(0,-17,0);
					glVertex3f(0,-17,17);
					glVertex3f(0,17,17);
				}glEnd();
			
			}glPopMatrix();


			//Back (luggage) cube

			glPushMatrix();
			{	
		
				glColor3f(.5,0,0);
				glTranslatef(-50,0,-10);
				glScalef(.6,1,.5);
				glutSolidCube(40);
		
		
			}glPopMatrix();

			//back(luggage)support(tringle)
			glPushMatrix();
			{	
		
				glColor3f(.5,0,0);
				glTranslatef(-40,-20,0);
				glBegin(GL_TRIANGLES);{
					glVertex3f(0,0,0);
					glVertex3f(-15,0,0);
					glVertex3f(0,0,20);
				}glEnd();
			
			}glPopMatrix();

			//back(luggage) support(tringle)
			glPushMatrix();
			{	
		
				glColor3f(.5,0,0);
				glTranslatef(-40,20,0);
				glBegin(GL_TRIANGLES);{
					glVertex3f(0,0,0);
					glVertex3f(-15,0,0);
					glVertex3f(0,0,20);
				}glEnd();
			
			}glPopMatrix();
			//back glass
			glPushMatrix();
			{	
		
				glColor4f(.1,.1,.1,0.8);
				glTranslatef(-55,0,0);
				glRotated(35,0,1,0);
				glBegin(GL_QUADS);{
					glVertex3f(0,17,0);
					glVertex3f(0,-17,0);
					glVertex3f(0,-17,17);
					glVertex3f(0,17,17);
				}glEnd();
			
			}glPopMatrix();

			//front window 1
			glPushMatrix();
			{	
		
				glColor4f(.1,.1,.1,0.8);
				glTranslatef(10,-21,0);
				glBegin(GL_QUADS);{
					glVertex3f(0,0,0);
					glVertex3f(0,0,15);
					glVertex3f(20,0,15);
					glVertex3f(30,0,0);
			
			
				}glEnd();
			
			}glPopMatrix();
			//front window 2
			glPushMatrix();
			{	
		
				glColor4f(.1,.1,.1,0.8);
				glTranslatef(10,21,0);
				glBegin(GL_QUADS);{
					glVertex3f(0,0,0);
					glVertex3f(0,0,15);
					glVertex3f(20,0,15);
					glVertex3f(30,0,0);
			
			
				}glEnd();
			
			}glPopMatrix();

			//back window 1
			glPushMatrix();
			{	
		
				glColor4f(.1,.1,.1,0.8);
				glTranslatef(-5,-21,0);
				glBegin(GL_QUADS);{
					glVertex3f(0,0,0);
					glVertex3f(0,0,15);
					glVertex3f(-25,0,15);
					glVertex3f(-35,0,0);
			
			
				}glEnd();
			
			}glPopMatrix();

			//back window 2
			glPushMatrix();
			{	
		
				glColor4f(.1,.1,.1,0.8);
				glTranslatef(-5,21,0);
				glBegin(GL_QUADS);{
					glVertex3f(0,0,0);
					glVertex3f(0,0,15);
					glVertex3f(-25,0,15);
					glVertex3f(-35,0,0);
			
			
				}glEnd();
			
			}glPopMatrix();


			//headlight 1
			glPushMatrix();
			{	
		
				glColor3f(.8,1,.8);
				glTranslatef(82,-10,-8);
				glScalef(.5,.8,1);
				glutSolidSphere(3.5,20,20);						
			
			}glPopMatrix();
	
			//headlight 2
			glPushMatrix();
			{	
		
				glColor3f(.8,1,.8);
				glTranslatef(82,10,-8);
				glScalef(.5,1,1);
				glutSolidSphere(3.5,20,20);						
			
			}glPopMatrix();

			//backlight
			glPushMatrix();
			{	
		
				glColor3f(1,0,0);
				glTranslatef(-63,10,-10);
				glBegin(GL_QUADS);{
					glVertex3f(0,5,0);
					glVertex3f(0,-5,0);
					glVertex3f(0,-5,7);
					glVertex3f(0,5,7);
			
			
				}glEnd();
			
			}glPopMatrix();
			//back light2
			glPushMatrix();
			{	
		
				glColor3f(1,0,0);
				glTranslatef(-63,-10,-10);
				glBegin(GL_QUADS);{
					glVertex3f(0,5,0);
					glVertex3f(0,-5,0);
					glVertex3f(0,-5,7);
					glVertex3f(0,5,7);
			
			
				}glEnd();
			
			}glPopMatrix();			


		}
		glPopMatrix();

	}
	glPopMatrix();
}

void display(){
	//codes for Models, Camera
	
	//clear the display
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,1,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		//clear buffers to preset values

	/***************************
	/ set-up camera (view) here
	****************************/ 
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);		//specify which matrix is the current matrix

	//initialize the matrix
	glLoadIdentity();				//replace the current matrix with the identity matrix [Diagonals have 1, others have 0]

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(0,-150,20,	0,0,0,	0,0,1);
	gluLookAt(cameraRadius*sin(cameraAngle), -cameraRadius*cos(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	
	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/**************************************************
	/ Grid and axes Lines(You can remove them if u want)
	***************************************************/
	// draw the three major AXES
	glBegin(GL_LINES);
		//X axis
		glColor3f(0, 1, 0);	//100% Green
		glVertex3f(-150, 0, 0);
		glVertex3f( 150, 0, 0);
		
		//Y axis
		glColor3f(0, 0, 1);	//100% Blue
		glVertex3f(0, -150, 0);	// intentionally extended to -150 to 150, no big deal
		glVertex3f(0,  150, 0);
		
		//Z axis
		glColor3f(1, 1, 1);	//100% White
		glVertex3f( 0, 0, -150);
		glVertex3f(0, 0, 150);
	glEnd();

	//some gridlines along the field
	//int i;
	//if(canDrawGrid){
	//glColor3f(0.5, 0.5, 0.5);	//grey
	//	glBegin(GL_LINES);
	//		for(i=-10;i<=10;i++){

	//			if(i==0)
	//				continue;	//SKIP the MAIN axes

	//			//lines parallel to Y-axis
	//			glVertex3f(i*10, -100, 0);
	//			glVertex3f(i*10,  100, 0);

	//			//lines parallel to X-axis
	//			glVertex3f(-100, i*10, 0);
	//			glVertex3f( 100, i*10, 0);
	//		}
	//	glEnd();
	//}
	//
	
	


	/****************************
	/ Add your objects from here
	****************************/
	//road
	glPushMatrix();
	{
		glColor3f(1,0,0);
		glBegin(GL_QUADS);{
			glVertex3f(-30,-150,0);
			glVertex3f(-28,-150,0);
			glVertex3f(-20,200,0);
			glVertex3f(-18,200,0);
			
			
		}glEnd();
		glBegin(GL_QUADS);{
			glVertex3f(30,-150,0);
			glVertex3f(28,-150,0);
			glVertex3f(20,200,0);
			glVertex3f(18,200,0);
			
			
		}glEnd();
		//yellow divider
		for(int i=-150;i<200;i=i+20)
		{
			glColor3f(1,1,0);
			glBegin(GL_QUADS);{
			glVertex3f(-1,i,0);
			glVertex3f(1,i,0);
			glVertex3f(1,i+15,0);
			glVertex3f(-1,i+15,0);
			
			
		}glEnd();

		}

	}
	glPopMatrix();
	//road color
	glPushMatrix();
	{
		glTranslatef(0,0,-1);
		glColor3f(.2,.2,.2);
			glBegin(GL_QUADS);{
			glVertex3f(-29,-150,0);
			glVertex3f(29,-150,0);
			glVertex3f(19,200,0);
			glVertex3f(-19,200,0);
			}glEnd();
	}
	glPopMatrix();



	//calling car function
	glPushMatrix();{
		glTranslatef(carcentrex,carcentrey,carcentrez);
		car(0);	
	}glPopMatrix();
	

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate(){
	//codes for any changes in Models, Camera
	
	//cameraAngle += cameraAngleDelta;	// camera will rotate at 0.002 radians per frame.
	
	//codes for any changes in Models

	//MISSING SOMETHING? -- YES: add the following
	glutPostRedisplay();	//this will call the display AGAIN

}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case 'd':
			if(carcentrex<=20)
			{
				carcentrex+=speed;	
				break;
			}
			else
				break;
				
			

		case 'a':	
			if(carcentrex>=-20)
			{
				carcentrex-=speed;	
				break;
			}
			else
				break;

		case 'w':	
			if(carcentrey<=150)
			{
				carcentrey+=speed;	
				break;
			}
			else
				break;
		
		case 's':	
			if(carcentrey>=-100)
			{
				carcentrey-=speed;	
				break;
			}
			else
				break;

		case '8':	//toggle grids
			canDrawGrid = 1 - canDrawGrid;
			break;
			
		case 'p':	//toggle grids
			cameraAngleDelta = 0;
			break;
		case 'r':	//toggle grids
			cameraAngleDelta = .001;
			break;		

		default:
			break;
	}
}


void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			cameraRadius += 10;
			break;
		case GLUT_KEY_UP:		// up arrow key
			if(cameraRadius > 10)
				cameraRadius -= 10;
			break;

		case GLUT_KEY_RIGHT:
			cameraAngle += 0.01;
			break;
		case GLUT_KEY_LEFT:
			cameraAngle -= 0.01;
			break;

		case GLUT_KEY_PAGE_UP:
			cameraHeight += 10;
			break;
		case GLUT_KEY_PAGE_DOWN:
			cameraHeight -= 10;
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}


void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
				cameraAngleDelta = -cameraAngleDelta;	
			}
			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}



void init(){
	//codes for initialization

	cameraAngle = 0;	//angle in radian
	cameraAngleDelta = 0.001;
	canDrawGrid = 1;

	cameraHeight = 50;
	cameraRadius = 150;
	//clear the screen
	glClearColor(0,0,0, 0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);
	
	//initialize the matrix
	glLoadIdentity();

	/*
		gluPerspective() — set up a perspective projection matrix

		fovy -         Specifies the field of view angle, in degrees, in the y direction.
        aspect ratio - Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
        zNear -        Specifies the distance from the viewer to the near clipping plane (always positive).
        zFar  -        Specifies the distance from the viewer to the far clipping plane (always positive).
    */
	
	gluPerspective(70,	1,	0.1,	10000.0);
	
}

int main(int argc, char **argv){
	
	glutInit(&argc,argv);							//initialize the GLUT library
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	
	/*
		glutInitDisplayMode - inits display mode
		GLUT_DOUBLE - allows for display on the double buffer window
		GLUT_RGBA - shows color (Red, green, blue) and an alpha
		GLUT_DEPTH - allows for depth buffer
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	

	glutCreateWindow("Some Title");

	init();						//codes for initialization

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	//ADD keyboard listeners:
	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	//ADD mouse listeners:
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
