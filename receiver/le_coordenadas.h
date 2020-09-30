/*
Módulo auxiliar para fazer fazer a leitura das coordenadas

Código desenvolvido por Beatriz Passanezi
*/


#include "mbed.h"
#include "nRF24L01P.h"

// Definicao dos pinos usados
extern Serial pc; // tx, rx

extern nRF24L01P my_nrf24l01p;    // mosi, miso, sck, csn, ce, irq

extern DigitalOut myled1;
extern DigitalOut myled2;

// Definicao da funcao usada
int le_coordenada();
