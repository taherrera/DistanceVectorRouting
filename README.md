
## Distance Vector Routing

Proyecto de curso Pontificia Universidad Católica de Chile. Tópicos Avanzados en Control Automático.

# How to run

To compile and run for only one node do:

    make posix && sudo ./main

root is required in order to read sockets.

To compile and run another node change in src/constants.h:

    MYROUTERID ROUTERID_0

to:

    MYROUTERID ROUTERID_X

X in [0..6]

and run and compile again.


For compiling 6 nodes automatically do:

    ./run_all.sh

Note: MYROUTERID must be set to ROUTERID\_0 to run this bash






