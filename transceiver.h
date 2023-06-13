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

#ifndef __TRANSCEIVER_H
#define __TRANSCEIVER_H

/** include files **/
#include "atomic.h"  // class Atomic

/** declarations **/
class Transceiver: public Atomic
{
public:
	Transceiver( const string &name = "Transceiver" ) ;	 // Default constructor	

	virtual string className() const
		{return "Transceiver";}

protected:
	Model &initFunction();
		
	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &inApp, &inGateway, &position;
	Port &outApp, &outGateway1, &outGateway2, &positionSet1, &positionSet2;	
	int oid ;
	int gatewayID;
	int inportID;
	Time sendTime;
	
	
};	// class Transceiver


#endif   //__TRANSCEIVER_H