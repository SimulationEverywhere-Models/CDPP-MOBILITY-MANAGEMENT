/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "gatewayqueue.h"      // class Queue
#include "gateway.h"    // class Generator
#include "tupleclient.h"        // class CPU
#include "tupleserver.h"   // class Transducer
#include "tuplequeue.h"    // class Trafico
#include "transceiver.h"
#include "mobilitymodule.h"
#include "transqueue.h"
#include "queue.h"
#include "cpu.h"

void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Gatewayqueue>() , "Gatewayqueue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Gateway>() , "Gateway" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Tupleclient>() , "Tupleclient" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Tupleserver>() , "Tupleserver" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Tuplequeue>() , "Tuplequeue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transceiver>() , "Transceiver" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Mobilitymodule>() , "Mobilitymodule" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transqueue>() , "Transqueue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;

}
