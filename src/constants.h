#ifndef CONSTANTS_H
#define CONSTANTS_H


/*
*
*  First order filter constant
*
*/ 

#define A 0.5


/*
*
*  Link constants
*
*/

#define CHANNEL 26

#define AGETIMEOUT 5

#define PERIOD 10 // in seconds

#define DB_INF 40
#define DB_20 20
#define DB_10 10
#define DB_2  2
#define DB_MINF 0


#define QUALITY_DB20 3
#define QUALITY_DB10 2
#define QUALITY_DB2  1
#define QUALITY_DB2M 0

#define LINKCOST_DB20 1
#define LINKCOST_DB10 2
#define LINKCOST_DB2  4
#define LINKCOST_DB2M 0


/*
*
*  Router IDs (Extended 16bit MAC 802.15.4 address)
*
*/


#define ROUTERID_0 0
#define ROUTERID_1 1
#define ROUTERID_2 2
#define ROUTERID_3 3
#define ROUTERID_4 4
#define ROUTERID_5 5



/*
*
*  Mesh Constants
*
*/

#define MAXROUTERS 6


/*
*
*  Router identifier constant
*
*/

#define MYROUTERID ROUTERID_0
 


#endif
