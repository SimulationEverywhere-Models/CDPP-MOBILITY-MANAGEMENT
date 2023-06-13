[top]
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


[queue]
preparation : 00:00:00:010