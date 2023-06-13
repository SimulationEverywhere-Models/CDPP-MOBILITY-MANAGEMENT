/*******************************************************************
*
*  DESCRIPTION: class GatewayQueue
*
*  AUTHOR: Umar Farooq
*
*  EMAIL: ufarooq@sce.carleton.ca
*
*  DATE: 17/10/2003
*
*******************************************************************/
/** include files **/
#include "gatewayqueue.h"      // class GatewayQueue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: GatewayQueue
* Description: Constructor
********************************************************************/
Gatewayqueue::Gatewayqueue( const string &name )
: Atomic( name )
, inCObject( addInputPort( "inCObject" ) )
, inSObject( addInputPort( "inSObject" ) )
, handoff( addInputPort( "handoff" ) )
, done( addInputPort( "done" ) )
, outCObject( addOutputPort( "outCObject" ) )
, outSObject( addOutputPort( "outSObject" ) )
, registerClient( addOutputPort( "registerClient" ) )
, preparationTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Gatewayqueue::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Gatewayqueue::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == inCObject )
	{
		j.objid = msg.value();
		j.portid = 1; 
		elements.push_back( j ) ;
		if( elements.size() == 1 )
			holdIn( active, preparationTime );
	}
	
	if( msg.port() == inSObject )
	{
		j.objid = msg.value();
		j.portid = 2; 
		elements.push_back( j ) ;
		if( elements.size() == 1 )
			holdIn( active, preparationTime );
	}

	if( msg.port() == handoff )
	{
		j.objid = msg.value();
		j.portid = 3; 
		elements.push_back( j ) ;
		if( elements.size() == 1 )
			holdIn( active, preparationTime );
	}

	if( msg.port() == done )
	{
		elements.pop_front() ;
		if( !elements.empty() )
			holdIn( active, preparationTime );
	}

	

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Gatewayqueue::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Gatewayqueue::outputFunction( const InternalMessage &msg )
{
	if(elements.front().portid == 1){
		sendOutput( msg.time(), outCObject, elements.front().objid ) ;
	}
	else if(elements.front().portid == 2){
		sendOutput( msg.time(), outSObject, elements.front().objid ) ;
	}
	else if(elements.front().portid == 3){
		sendOutput( msg.time(), registerClient, elements.front().objid ) ;
	}

	return *this ;
}
