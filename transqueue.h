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

#ifndef __TRANSQUEUE_H
#define __TRANSQUEUE_H

#include <list>
#include "atomic.h"     // class Atomic

class Transqueue : public Atomic
{
public:
	Transqueue( const string &name = "Transqueue" );					//Default constructor

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
	const Port &inApp;
	const Port &inGateway;
	const Port &position;
	const Port &done;
	Port &outCObject;
	Port &outSObject;
	Port &location;
	Time preparationTime;
	typedef list<jobs> ElementList ;
	ElementList elements ;
	jobs j;
	
};	// class Queue

// ** inline ** // 
inline
string Transqueue::className() const
{
	return "Transqueue" ;
}


#endif   //__TRANSQUEUE_H
