/*******************************************************************
*
*  DESCRIPTION: class TupleClient
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
#include "tupleclient.h"           // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator

/*******************************************************************
* Function Name: TupleClient
* Description: constructor
********************************************************************/
Tupleclient::Tupleclient( const string &name )
: Atomic( name )
, inCObject( addInputPort( "inCObject" ) )
, outCObject( addOutputPort( "outCObject" ) )
{ }
	

Model &Tupleclient::initFunction()
{
	writeTime = "00:00:02:000";	
	return *this ;
}



/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Tupleclient::externalFunction( const ExternalMessage &msg )
{
	oid = static_cast< int >( msg.value() ) ;
	holdIn( active,writeTime) ;
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Tupleclient::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Tupleclient::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), outCObject, oid );
	return *this;
}

