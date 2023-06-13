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

#ifndef __TUPLECLIENT_H
#define __TUPLECLIENT_H

/** include files **/
#include "atomic.h"  // class Atomic

/** declarations **/
class Tupleclient: public Atomic
{
public:
	Tupleclient( const string &name = "Tupleclient" ) ;	 // Default constructor

	virtual string className() const
		{return "Tupleclient";}

protected:
	Model &initFunction();
		
	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &inCObject ;
	Port &outCObject ;
	int oid ;
	Time writeTime;

};	// class CPU


#endif   //__TUPLECLIENT_H 
