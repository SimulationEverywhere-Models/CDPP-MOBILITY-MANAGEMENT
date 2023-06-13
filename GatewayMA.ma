[top]
components : gateway@Gateway
in : inCObject inSObject handoff
out : outCObject outSObject registerClient
Link : inCObject inCObject@gateway
Link : inSObject inSObject@gateway
Link : handoff handoff@gateway
Link : outCObject@gateway outCObject
Link : outSObject@gateway outSObject
Link : registerClient@gateway registerClient
