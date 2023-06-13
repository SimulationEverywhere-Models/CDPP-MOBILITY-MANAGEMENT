[top]
components : MobileTerminal 
components : WirelessGateway1 
components : WirelessGateway2
components : TupleSpace
components : Server
In : inApp
Out : clientobjectoutofgateway1 clientobjectoutofgateway2 clientobjectoutoftuple objectoutofserver outApp serverobjectoutofgateway1 serverobjectoutofgateway2
Link : inApp inApp@MobileTerminal
Link : outG1@MobileTerminal inC@WirelessGateway1
Link : outG2@MobileTerminal inC@WirelessGateway2
Link : pG1@MobileTerminal handoff@WirelessGateway1
Link : pG2@MobileTerminal handoff@WirelessGateway2
Link : outS@WirelessGateway1 inG@MobileTerminal
Link : outS@WirelessGateway2 inG@MobileTerminal
Link : outC@WirelessGateway1 clientobjectoutofgateway1
Link : outC@WirelessGateway2 clientobjectoutofgateway2
Link : outC@WirelessGateway1 inC@TupleSpace
Link : outC@WirelessGateway2 inC@TupleSpace
Link : register@WirelessGateway1 RC@TupleSpace
Link : register@WirelessGateway2 RC@TupleSpace
Link : outS1@TupleSpace inS@WirelessGateway1
Link : outS2@TupleSpace inS@WirelessGateway2
Link : outC@TupleSpace inC@Server
Link : outC@TupleSpace clientobjectoutoftuple
Link : outS@Server inS@TupleSpace
Link : outS@Server objectoutofserver
Link : outApp@MobileTerminal outApp
Link : outS@WirelessGateway1 serverobjectoutofgateway1
Link : outS@WirelessGateway2 serverobjectoutofgateway2

[WirelessGateway1]
components : gw1@Gateway
components : gwq1@Gatewayqueue
in : inS inC handoff
out : outS outC register
Link : inC inCObject@gwq1
Link : inS inSObject@gwq1
Link : handoff handoff@gwq1
Link : outCObject@gwq1 inCObject@gw1
Link : outSObject@gwq1 inSObject@gw1
Link : registerClient@gwq1 handoff@gw1
Link : outCObject@gw1 outC
Link : outCObject@gw1 done@gwq1
Link : outSObject@gw1 outS
Link : outSObject@gw1 done@gwq1
Link : registerClient@gw1 register
Link : registerClient@gw1 done@gwq1

[WirelessGateway2]
components : gw2@Gateway
components : gwq2@Gatewayqueue
in : inS inC handoff
out : outS outC register
Link : inC inCObject@gwq2
Link : inS inSObject@gwq2
Link : handoff handoff@gwq2
Link : outCObject@gwq2 inCObject@gw2
Link : outSObject@gwq2 inSObject@gw2
Link : registerClient@gwq2 handoff@gw2
Link : outCObject@gw2 outC
Link : outCObject@gw2 done@gwq2
Link : outSObject@gw2 outS
Link : outSObject@gw2 done@gwq2
Link : registerClient@gw2 register
Link : registerClient@gw2 done@gwq2

[MobileTerminal]
components : mob@Mobilitymodule
components : trans@Transceiver
components : queue@Transqueue 
in : inApp inG
out : outG1 outG2 pG1 pG2 outApp
Link : inApp inApp@queue
Link : inG inGateway@queue
Link : outCObject@queue inApp@trans
Link : outSObject@queue inGateway@trans
Link : location@queue position@trans
Link : location@mob position@queue
Link : outApp@trans outApp
Link : outApp@trans done@queue
Link : outGateway1@trans done@queue
Link : outGateway1@trans outG1
Link : outGateway2@trans done@queue
Link : outGateway2@trans outG2
Link : positionSet1@trans done@queue
Link : positionSet2@trans done@queue
Link : positionSet1@trans pG1
Link : positionSet2@trans pG2

[TupleSpace]
components : tqueue@Queue
components : tClient@Tupleclient
components : tSqueue@Tuplequeue
components : tServer@Tupleserver
in : inC inS RC
out : outC outS1 outS2
Link : inC in@tqueue
Link : out@tqueue inCObject@tClient
Link : outCObject@tClient outC
Link : outCObject@tClient done@tqueue
Link : RC registerClient@tSqueue
Link : inS inSObject@tSqueue
Link : registerC@tSqueue registerClient@tServer
Link : outSObject@tSqueue inSObject@tServer
Link : outSObject1@tServer outS1
Link : outSObject2@tServer outS2
Link : outSObject1@tServer done@tSqueue
Link : outSObject2@tServer done@tSqueue
Link : cRegistered@tServer done@tSqueue

[Server]
components : serv@CPU
components : serverQueue@Queue
in : inC
out : outS
Link : inC in@serverQueue
Link : out@serverQueue in@serv
Link : out@serv outS
Link : out@serv done@serverQueue

[queue]
preparation : 00:00:00:010

[gwq1]
preparation : 00:00:00:010

[gwq2]
preparation : 00:00:00:010

[tqueue]
preparation : 00:00:00:010

[tSqueue]
preparation : 00:00:00:010

[serverQueue]
preparation : 00:00:00:010

[serv]
distribution : normal
mean : 10
deviation : 2