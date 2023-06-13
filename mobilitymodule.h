/*******************************************************************
*
*  DESCRIPTION: class MobilityModule
*
*  AUTHOR: Umar Farooq
*
*  EMAIL: ufarooq@sce.carleton.ca
*
*  DATE: 17/10/2003
*
*******************************************************************/

#ifndef __MOBILITYMODULE_H
#define __MOBILITYMODULE_H

/** include files **/
#include "atomic.h"     // class Atomic
#include "except.h"     // class InvalidMessageException

/** declarations **/
class Mobilitymodule : public Atomic
{
public:
	Mobilitymodule( const string &name = "Mobilitymodule" );				  // Default constructor

	virtual string className() const
		{return "Mobilitymodule";}

protected:
	Model &initFunction() ;

	Model &externalFunction( const ExternalMessage & )
			{throw InvalidMessageException();}

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	Port &location;
	int currentGatewayID;
	Time handoffTime;
	
};	// class MobilityModule


#endif   //__MOBILITYMODULE_H 
