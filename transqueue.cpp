/*******************************************************************
*
*  DESCRIPTION: class TransQueue
*
*  AUTHOR: Umar Farooq
*
*  EMAIL: ufarooq@sce.carleton.ca
*
*  DATE: 17/10/2003
*
*******************************************************************/

/** include files **/
#include "transqueue.h"      // class Transqueue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: TransQueue
* Description: Constructor
********************************************************************/
Transqueue::Transqueue( const string &name )
: Atomic( name )
, inApp( addInputPort( "inApp" ) )
, position( addInputPort( "position" ) )
, inGateway( addInputPort( "inGateway" ) )
, done( addInputPort( "done" ) )
, outCObject( addOutputPort( "outCObject" ) )
, outSObject( addOutputPort( "outSObject" ) )
, location( addOutputPort( "location" ) )
, preparationTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Transqueue::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Transqueue::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == inApp )
	{
		j.objid = msg.value();
		j.portid = 1; 
		elements.push_back( j ) ;
		if( elements.size() == 1 )
			holdIn( active, preparationTime );
	}
	
	if( msg.port() == inGateway )
	{
		j.objid = msg.value();
		j.portid = 2; 
		elements.push_back( j ) ;
		if( elements.size() == 1 )
			holdIn( active, preparationTime );
	}

	if( msg.port() == position )
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
Model &Transqueue::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Transqueue::outputFunction( const InternalMessage &msg )
{
	if(elements.front().portid == 1){
		sendOutput( msg.time(), outCObject, elements.front().objid ) ;
	}
	else if(elements.front().portid == 2){
		sendOutput( msg.time(), outSObject, elements.front().objid ) ;
	}
	else if(elements.front().portid == 3){
		sendOutput( msg.time(), location, elements.front().objid ) ;
	}

	return *this ;
}
