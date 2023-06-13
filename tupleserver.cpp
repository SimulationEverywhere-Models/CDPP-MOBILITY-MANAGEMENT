/*******************************************************************
*
*  DESCRIPTION: class TupleServer
*
*  AUTHOR: Umar Farooq
*
*  EMAIL: ufarooq@sce.carleton.ca
*
*  DATE: 17/10/2003
*
*******************************************************************/

/** include files **/
#include <math.h>        
#include "tupleserver.h"           // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator

/*******************************************************************
* Function Name: TupleQueue
* Description: constructor
********************************************************************/
Tupleserver::Tupleserver( const string &name )
: Atomic( name )
, inSObject( addInputPort( "inSObject" ) )
, registerClient( addInputPort( "registerClient" ) )
, outSObject1( addOutputPort( "outSObject1" ) )
, outSObject2( addOutputPort( "outSObject2" ) )
, cRegistered( addOutputPort( "cRegistered" ) )

{ }

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Tupleserver::initFunction()
{
	gatewayID = 1;
	inportID = 1;
	transferTime = "00:00:00:100";	
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Tupleserver::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == inSObject ){
		oid = static_cast< int >( msg.value() ) ;
		inportID = 1;
		holdIn( active,transferTime) ;		
	}
	else if (msg.port() == registerClient){
		gatewayID = static_cast< int >( msg.value() ) ;
		inportID = 2;
		holdIn(active,Time::Zero);
	}
	
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Tupleserver::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Tupleserver::outputFunction( const InternalMessage &msg )
{
	if (inportID == 1){
		if(gatewayID == 1){
			sendOutput( msg.time(), outSObject1, oid );
		}
		else{
			sendOutput( msg.time(), outSObject2, oid );
		}
	}
	else if (inportID == 2){
		sendOutput(msg.time(), cRegistered, gatewayID);
	}	
	
	return *this;
}

