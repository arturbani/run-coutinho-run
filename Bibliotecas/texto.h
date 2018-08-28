void texto(void* font, char* s, float x, float y){
  unsigned int i;
  glRasterPos2f(x, y);

  for (i=0; i<strlen(s); i++){
      glutBitmapCharacter(font, s[i]);
    }
}

void telaFim(){
glColor4f(0, 0, 0, 0.1);

glBegin(GL_POLYGON);

  glVertex2d(0, 0);
  glVertex2d(0, 100);
  glVertex2d(100, 100);
  glVertex2d(100, 0);

glEnd();

glColor3f(0, 0, 0);
texto(GLUT_BITMAP_HELVETICA_18, "PERDEU OTARIO!", 25, 50);


}
