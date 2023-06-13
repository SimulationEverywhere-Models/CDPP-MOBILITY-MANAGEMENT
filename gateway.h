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
#ifndef __GATEWAY_H
#define __GATEWAY_H

/** include files **/
#include "atomic.h"  // class Atomic

/** declarations **/
class Gateway: public Atomic
{
public:
	Gateway( const string &name = "Gateway" ) ;	 // Default constructor	

	virtual string className() const
		{return "Gateway";}

protected:
	Model &initFunction();		
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &inCObject, &inSObject, &handoff;
	Port &outCObject, &outSObject, &registerClient;	
	int oid ;
	int inportID;
	Time sendTime;
	
	
};	// class Transceiver


#endif   //__GATEWAY_H