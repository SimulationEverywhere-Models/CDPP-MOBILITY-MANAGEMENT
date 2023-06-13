[top]
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


[gwq1]
preparation : 00:00:00:010
