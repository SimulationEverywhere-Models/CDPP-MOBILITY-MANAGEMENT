/*******************************************************************
*
*  DESCRIPTION: class Gateway
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
#include "gateway.h"           // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator

/*******************************************************************
* Function Name: Gateway
* Description: constructor
********************************************************************/
Gateway::Gateway( const string &name )
: Atomic( name )
, inCObject( addInputPort( "inCObject" ) )
, inSObject( addInputPort( "inSObject" ) )
, handoff( addInputPort( "handoff" ) )
, outCObject( addOutputPort( "outCObject" ) )
, outSObject( addOutputPort( "outSObject" ) )
, registerClient( addOutputPort( "registerClient" ) )

{ }


Model &Gateway::initFunction()
{
	inportID = 1;
	sendTime = "00:00:00:100";	
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Gateway::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == inCObject ){
		oid = static_cast< int >( msg.value() ) ;
		inportID = 1;
		holdIn( active,sendTime) ;		
	}
	else if (msg.port() == inSObject){
		oid = static_cast< int >( msg.value() ) ;
		inportID = 2;
		holdIn(active,sendTime);
	}
	else { 
		oid = static_cast< int >( msg.value() ) ;
		inportID = 3;
		holdIn(active,sendTime) ;		
	}
	

	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Gateway::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Gateway::outputFunction( const InternalMessage &msg )
{
	if (inportID == 1){
		sendOutput( msg.time(), outCObject, oid );
	}
	else if (inportID == 2){
		sendOutput(msg.time(), outSObject, oid);
	}

	else if (inportID == 3){
		sendOutput(msg.time(), registerClient, oid);
	}
	
	return *this;
}

