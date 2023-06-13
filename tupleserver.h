/*******************************************************************
*
*  DESCRIPTION: class CPU (processes jobs with a specified
*               distribution)
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#ifndef __TUPLESERVER_H
#define __TUPLESERVER_H

/** include files **/
#include "atomic.h"  // class Atomic

/** declarations **/
class Tupleserver: public Atomic
{
public:
	Tupleserver( const string &name = "Tupleserver" ) ;	 // Default constructor	

	virtual string className() const
		{return "Tupleserver";}

protected:
	Model &initFunction();
		
	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &inSObject, &registerClient;
	Port &outSObject1, &outSObject2, &cRegistered;	
	int oid ;
	int gatewayID;
	int inportID;
	Time transferTime;
	
	
};	// class Transceiver


#endif   //__TUPLESERVER_H