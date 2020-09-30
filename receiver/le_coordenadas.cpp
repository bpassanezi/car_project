/*
Módulo auxiliar para fazer fazer a leitura das coordenadas

Código desenvolvido por Beatriz Passanezi
*/

#include "mbed.h"
#include "nRF24L01P.h"
#include "le_coordenadas.h"

// Funcao que le as coordenadas recebidas pelo tranceiver
int le_coordenada() {

// The nRF24L01+ supports transfers from 1 to 32 bytes, but Sparkfun's
//  "Nordic Serial Interface Board" (http://www.sparkfun.com/products/9019)
//  only handles 4 byte transfers in the ATMega code.
#define TRANSFER_SIZE   4

    char rxData[TRANSFER_SIZE];
    int rxDataCnt = 0;

    my_nrf24l01p.powerUp();

    my_nrf24l01p.setTransferSize( TRANSFER_SIZE );
    my_nrf24l01p.setReceiveMode();
    my_nrf24l01p.enable();
        
    int coord = 0;
        
    // Logica para realizar a leitura da coordenada
    while(coord == 0){
        if ( my_nrf24l01p.readable() ) {
            // ...read the data into the receive buffer
            rxDataCnt = my_nrf24l01p.read( NRF24L01P_PIPE_P0, rxData, sizeof(rxData));
            
            // Transformando o vetor de char recebidos em uma coordenada
            char num[TRANSFER_SIZE];
            num[0] = rxData[0];
            num[1] = rxData[1];
            num[2] = rxData[2];
            num[3] = rxData[3];
                
            sscanf(num, "%d", &coord);
            pc.printf("\n\r Coordenada recebida: %d", coord);
            break;
        }
    }
    return coord;       
}
