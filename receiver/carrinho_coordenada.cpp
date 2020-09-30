/*
Módulo auxiliar para fazer o carrinho andar até a coordenada correta

Código desenvolvido por Beatriz Passanezi
*/

#include "mbed.h"
#include "carrinho_coordenada.h"

int pulses1 = 0, pulses2 = 0;

// Funções auxiliares usadas para fazer o carrinho andar para trás, para frente
// para a direita e para a esquerda
void go_back(mbed::PwmOut& IN1, mbed::PwmOut& IN2, mbed::PwmOut& IN3, mbed::PwmOut& IN4)
{
     IN1.write(0.555f);      // 50% duty cycle, relative to period
     IN2.write(0.0f);
     IN3.write(0.6f);
     IN4.write(0.0);
}

void go_forward(mbed::PwmOut& IN1, mbed::PwmOut& IN2, mbed::PwmOut& IN3, mbed::PwmOut& IN4)
{
     IN1.write(0.0f);
     IN2.write(0.555f);
     IN3.write(0.0f);
     IN4.write(0.6f);
}

void stop(mbed::PwmOut& IN1, mbed::PwmOut& IN2, mbed::PwmOut& IN3, mbed::PwmOut& IN4)
{
     IN1.write(1.0f);
     IN2.write(1.0f);
     IN3.write(1.0f);
     IN4.write(1.0f);
}

void turn_right(mbed::PwmOut& IN1, mbed::PwmOut& IN2, mbed::PwmOut& IN3, mbed::PwmOut& IN4)
{
     stop(IN1, IN2, IN3, IN4);
     wait(0.5);
         
     IN1.write(0.7f);
     IN2.write(0.0f);
     IN3.write(0.7f);
     IN4.write(0.7f);
     
     wait(1.2);
     stop(IN1, IN2, IN3, IN4);
}

void turn_left(mbed::PwmOut& IN1, mbed::PwmOut& IN2, mbed::PwmOut& IN3, mbed::PwmOut& IN4)
{
     stop(IN1, IN2, IN3, IN4);
     wait(0.5);
     
     IN1.write(0.7f);
     IN2.write(0.7f);
     IN3.write(0.7f);
     IN4.write(0.0f);
     
     wait(1.2);
     stop(IN1, IN2, IN3, IN4);
}

// Funções auxiliares para incrementar o valor dos encoders
void count1(){
    pulses1++;
    wait(0.005);
}

void count2(){
    pulses2++;
    wait(0.005);
}

// Função principal para dadas duas coordenadas (coordx, coordy)
// fazer o carrinho chegar nas coordenadas corretas
int go_to_coordenada(int coordx, int coordy) {
    
    // Definição da interrupção dos encoders
    ENCOD1.rise(&count1);
    ENCOD2.rise(&count2);
    
    IN1.period(1.0f);      // 1 second period
    IN2.period(1.0f);      // 1 second period
    IN3.period(1.0f);      // 1 second period
    IN4.period(1.0f);      // 1 second period
        
    // Logica que define a direção que o carrinho deve andar dadas as coordenadas 
    if (coordy > 0) {
        while(pulses1 <= coordy)
                go_forward(IN1, IN2, IN3, IN4);
            stop(IN1, IN2, IN3, IN4);
            pulses1 = 0;
            pulses2 = 0;
        }
        
        else if (coordy < 0) {
            while(pulses1 <= coordy)
                go_back(IN1, IN2, IN3, IN4);
            stop(IN1, IN2, IN3, IN4);
            pulses1 = 0;
            pulses2 = 0;
        }
        if (coordx > 0) {
            turn_right(IN1, IN2, IN3, IN4);
            pulses1 = 0;
            pulses2 = 0;
            while(pulses1 <= coordx)
                go_forward(IN1, IN2, IN3, IN4);
            stop(IN1, IN2, IN3, IN4);
            pulses1 = 0;
            pulses2 = 0;
        }
        
        else if (coordx < 0) {
            turn_left(IN1, IN2, IN3, IN4);
            pulses1 = 0;
            pulses2 = 0;
            while(pulses1 <= coordx)
                go_forward(IN1, IN2, IN3, IN4);
            stop(IN1, IN2, IN3, IN4);
            pulses1 = 0;
            pulses2 = 0;
        }
        
    return 0;
}