/*******************************************************************
*
*  DESCRIPTION: class TupleQueue
*
*  AUTHOR: Umar Farooq
*
*  EMAIL: ufarooq@sce.carleton.ca
*
*  DATE: 17/10/2003
*
*******************************************************************/

/** include files **/
#include "tuplequeue.h"      // class TupleQueue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Queue
********************************************************************/
Tuplequeue::Tuplequeue( const string &name )
: Atomic( name )
, inSObject( addInputPort( "inSObject" ) )
, registerClient( addInputPort( "registerClient" ) )
, done( addInputPort( "done" ) )
, outSObject( addOutputPort( "outSObject" ) )
, registerC( addOutputPort( "registerC" ) )
, preparationTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Tuplequeue::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Tuplequeue::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == inSObject )
	{
		j.objid = msg.value();
		j.portid = 1; 
		elements.push_back( j ) ;
		if( elements.size() == 1 )
			holdIn( active, preparationTime );
	}
	
	if( msg.port() == registerClient )
	{
		j.objid = msg.value();
		j.portid = 2; 
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
Model &Tuplequeue::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Tuplequeue::outputFunction( const InternalMessage &msg )
{
	if(elements.front().portid == 1){
		sendOutput( msg.time(), outSObject, elements.front().objid ) ;
	}
	else if(elements.front().portid == 2){
		sendOutput( msg.time(), registerC, elements.front().objid ) ;
	}

	return *this ;
}
