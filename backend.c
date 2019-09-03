#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "backend.h"

static void Gen_codigo_expresion(Expresion *expr) {
  switch(expr->tipo) {
    case 'D':
      printf("PUSH %d\n",expr->valor);
      break;
    case 'P':
      Gen_codigo_expresion(expr->izquierda);
      Gen_codigo_expresion(expr->derecha);
      switch (expr->oper) {
        case '+':
          printf("ADD\n");
          break;
        case '*':
          printf("MULT\n");
          break;
      }
      break;
  }
}


void Procesar(nodo_AST *codigoi){
  Gen_codigo_expresion(codigoi);
  printf("PRINT\n");
}
