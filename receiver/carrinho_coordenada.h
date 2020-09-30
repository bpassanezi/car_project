/*
Módulo auxiliar para fazer o carrinho andar até a coordenada correta

Código desenvolvido por Beatriz Passanezi
*/


#include "mbed.h"
#include "nRF24L01P.h"

// Definicao dos pinos usados
extern PwmOut IN1;
extern PwmOut IN2; 
extern PwmOut IN3;
extern PwmOut IN4;

extern InterruptIn  ENCOD1;
extern InterruptIn  ENCOD2;

// Definicao dos cabecalhos das funcoes
void go_back(mbed::PwmOut& IN1, mbed::PwmOut& IN2, mbed::PwmOut& IN3, mbed::PwmOut& IN4);

void go_forward(mbed::PwmOut& IN1, mbed::PwmOut& IN2, mbed::PwmOut& IN3, mbed::PwmOut& IN4);

void stop(mbed::PwmOut& IN1, mbed::PwmOut& IN2, mbed::PwmOut& IN3, mbed::PwmOut& IN4);

void turn_right(mbed::PwmOut& IN1, mbed::PwmOut& IN2, mbed::PwmOut& IN3, mbed::PwmOut& IN4);

void turn_left(mbed::PwmOut& IN1, mbed::PwmOut& IN2, mbed::PwmOut& IN3, mbed::PwmOut& IN4);

void count1();

void count2();

int go_to_coordenada(int coordx, int coordy);