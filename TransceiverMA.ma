[top]
components : trans@Transceiver
in : inApp inGateway position
out : outGateway1 outGateway2 positionSet1 positionSet2 outApp
Link : inApp inApp@trans
Link : inGateway inGateway@trans
Link : position position@trans
Link : outApp@trans outApp
Link : outGateway1@trans outGateway1
Link : outGateway2@trans outGateway2
Link : positionSet1@trans positionSet1
Link : positionSet2@trans positionSet2
