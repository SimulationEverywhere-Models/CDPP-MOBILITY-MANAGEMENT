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

#ifndef __TUPLEQUEUE_H
#define __TUPLEQUEUE_H

#include <list>
#include "atomic.h"     // class Atomic

class Tuplequeue : public Atomic
{
public:
	Tuplequeue( const string &name = "Tuplequeue" );					//Default constructor

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
	const Port &inSObject;
	const Port &registerClient;
	const Port &done;
	Port &outSObject;
	Port &registerC;
	Time preparationTime;
	typedef list<jobs> ElementList ;
	ElementList elements ;
	jobs j;
	
};	// class Queue

// ** inline ** // 
inline
string Tuplequeue::className() const
{
	return "Tuplequeue" ;
}


#endif   //__TUPLEQUEUE_H
