# car_project

This project was developed on the subject `PSI3422` at Escola Politécnica da  USP.

The project consists on sending a pair of coordinates `(X, Y)` from the computer to the car and the car should move as close as possible to the given location.

The project is divided on two main modules.

## Transmitter

The transmitter is responsible of sending a pair of coordinates `(X, Y)` in cm to the receiver. This transmission was implemented using  the module `nRF24L01P`.

## Receiver

The receiver is responsible for receiving the coordinates and then implementing all the logic needed to send the car to this location.

Below there is an example of the car working:

![lalala]("images/carrinho.gif")