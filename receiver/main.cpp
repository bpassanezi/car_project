/*
Código main para o receptor do carrinho

Código desenvolvido por Beatriz Passanezi
*/

#include "mbed.h"
#include "nRF24L01P.h"
#include "le_coordenadas.h"
#include "carrinho_coordenada.h"

// Definicao dos pinos usados
Serial pc(USBTX, USBRX); // tx, rx

nRF24L01P my_nrf24l01p(PTD2, PTD3, PTC5, PTD0, PTD5, PTA13);    // mosi, miso, sck, csn, ce, irq

DigitalOut myled1(LED1);
DigitalOut myled2(LED2);

PwmOut IN1(PTB0);
PwmOut IN2(PTB1);
PwmOut IN3(PTB2);
PwmOut IN4(PTB3);

InterruptIn  ENCOD1(PTA4); 
InterruptIn  ENCOD2(PTA5); 


int main() {
    
    pc.printf("\n\rLENDO COORDENADAS");
    // As coordenadas sao recebidas em cm, para transforma-las em numero de pulsos, preciso multiplicar por 5
    // Esse numero (5) foi obyido pela calibração do carrinho
    // sei que cada cm que o carrinho anda equivale a 5cm
    
    // Leitura e conversao das coordenadas de cm para numero de pulsos
    int coordx = (le_coordenada()*5);
    int coordy = (le_coordenada()*5);
    
    pc.printf("\n\r Coordenada X: %d", coordx);
    pc.printf("\n\r Coordenada Y: %d", coordy);
    
    // Movimentacao do carrinho ate as coordenadas
    go_to_coordenada(coordx, coordy);
}
