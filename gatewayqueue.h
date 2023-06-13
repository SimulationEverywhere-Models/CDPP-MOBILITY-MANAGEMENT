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

#ifndef __GATEWAYQUEUE_H
#define __GATEWAYQUEUE_H

#include <list>
#include "atomic.h"     // class Atomic

class Gatewayqueue : public Atomic
{
public:
	Gatewayqueue( const string &name = "Gatewayqueue" );					//Default constructor
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	struct jobs{
	int objid;
	int portid;
	};
	const Port &inCObject;
	const Port &inSObject;
	const Port &handoff;
	const Port &done;
	Port &outCObject;
	Port &outSObject;
	Port &registerClient;
	Time preparationTime;
	typedef list<jobs> ElementList ;
	ElementList elements ;
	jobs j;
	
};	// class Queue

// ** inline ** // 
inline
string Gatewayqueue::className() const
{
	return "Gatewayqueue" ;
}


#endif   //__GATEWAYQUEUE_H
