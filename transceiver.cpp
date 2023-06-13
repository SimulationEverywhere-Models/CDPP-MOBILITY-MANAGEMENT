/*******************************************************************
*
*  DESCRIPTION: class Transceiver
*
*  AUTHOR: Umar Farooq
*
*  EMAIL: ufarooq@sce.carleton.ca
*
*  DATE: 17/10/2003
*
*******************************************************************/

/** include files **/
#include <math.h>        // fabs( ... )
#include "transceiver.h"           // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator

/*******************************************************************
* Function Name: Transceiver
* Description: constructor
********************************************************************/
Transceiver::Transceiver( const string &name )
: Atomic( name )
, inApp( addInputPort( "inApp" ) )
, inGateway( addInputPort( "inGateway" ) )
, position( addInputPort( "position" ) )
, outApp( addOutputPort( "outApp" ) )
, outGateway1( addOutputPort( "outGateway1" ) )
, outGateway2( addOutputPort( "outGateway2" ) )
, positionSet1( addOutputPort( "positionSet1" ) )
, positionSet2( addOutputPort( "positionSet2" ) )

{ }


Model &Transceiver::initFunction()
{
	gatewayID = 1;
	inportID = 1;
	sendTime = "00:00:01:000";	
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Transceiver::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == inApp ){
		oid = static_cast< int >( msg.value() ) ;
		inportID = 1;
		holdIn( active,sendTime) ;		
	}
	else if (msg.port() == position){
		gatewayID = static_cast< int >( msg.value() ) ;
		inportID = 3;
		holdIn(active,Time::Zero);
	}
	else { 
		oid = static_cast< int >( msg.value() ) ;
		inportID = 2;
		holdIn(active,sendTime) ;		
	}
	

	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Transceiver::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Transceiver::outputFunction( const InternalMessage &msg )
{
	if (inportID == 1){
		if(gatewayID == 1){
			sendOutput( msg.time(), outGateway1, oid );
		}
		else{
			sendOutput( msg.time(), outGateway2, oid );
		}
	}
	else if (inportID == 2){
		sendOutput(msg.time(), outApp, oid);
	}

	else if (inportID == 3){
		if(gatewayID == 1){
			sendOutput( msg.time(), positionSet1, gatewayID);
		}
		else{
			sendOutput( msg.time(), positionSet2, gatewayID);
		}
	}
	
	return *this;
}

