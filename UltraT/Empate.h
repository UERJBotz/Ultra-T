#ifndef empate_H
#define empate_H

#include "PID.h"

void paraTras() { // estratégia número 6 no controle
  mover(-1023, -1023);
}

int EstadoAtual;

void EstadoUpdate(){  // função que atualiza os estados
  leituraSensoresSD();
  EstadoAtual = 1; // sem inimigo
  if (leitura[1] && leitura[2]){  // enxergando inimigo com os 2 sensores
    EstadoAtual = 2;
  } else if (!leitura[1] && leitura[2]){ // enxergando com o direito
    EstadoAtual = 3;
  } else if (leitura[1] && !leitura[2]){ // enxergando com o esquerdo
    EstadoAtual = 4;
    
  } 
  else {
    EstadoAtual = 1; // sem inimigo
  }
}

void SeekAndDestroy_L(){  // maquina de estados
  EstadoUpdate(); // função atualiza o estado a todo momento
  switch (EstadoAtual){
    case 1:
      
      Serial.println("Searching Enemy...");
      mover(1023, -1023);
      break;

    case 2:
      Serial.println("ROBOT ATTACK!");
      
      mover(1023, 1023);
      break;

     case 3:
      
      Serial.println("Left Detected!");
      mover(-1023, 1023);
      break;

      case 4:
      
      Serial.println("Right Detected!");
      mover(1023, -1023);
      break;
  }
}

void SeekAndDestroy_R(){  // maquina de estados
  EstadoUpdate(); // função atualiza o estado a todo momento

  switch (EstadoAtual){

    case 1:
      Serial.println("Searching Enemy...");
      mover(-1023, 1023);
      break;

    case 2:
      Serial.println("ROBOT ATTACK!");
      mover(1023, 1023);
      break;

    case 3:
      Serial.println("Left Detected!");
      mover(-1023, 1023);
      break;

    case 4:
      Serial.println("Right Detected!");
      mover(1023, -1023);
      break;
  }
}

#endif
