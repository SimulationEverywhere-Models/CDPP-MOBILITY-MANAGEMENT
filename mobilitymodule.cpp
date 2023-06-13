/*******************************************************************
*
*  DESCRIPTION: class MobilityModule
*
*  AUTHOR: Umar Farooq
*
*  EMAIL: ufarooq@sce.carleton.ca
*
*  DATE: 17/10/2003
*
*******************************************************************/

/** include files **/
#include "mobilitymodule.h"       // base header
#include "message.h"       // class InternalMessage 
#include "mainsimu.h"      // class Simulator

/*******************************************************************
* Function Name: MobilityModule
* Description: constructor
********************************************************************/
Mobilitymodule::Mobilitymodule( const string &name )
: Atomic( name )
, location( addOutputPort( "location" ) )
{ }

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Mobilitymodule::initFunction()
{
	currentGatewayID = 1;
	handoffTime = "00:00:30:000";
	holdIn( active, Time::Zero) ;
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Mobilitymodule::internalFunction( const InternalMessage & )
{
	holdIn( active, handoffTime) ;
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Mobilitymodule::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(),location,currentGatewayID) ;
	if(currentGatewayID == 1){
		currentGatewayID = 2;
	}
	else{
		currentGatewayID = 1;
	}
	return *this ;
}
