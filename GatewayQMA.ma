[top]
components : gatewayQ@Gatewayqueue
in : inCObject inSObject handoff done
out : outCObject outSObject registerClient
Link : inCObject inCObject@gatewayQ
Link : inSObject inSObject@gatewayQ
Link : handoff handoff@gatewayQ
Link : done done@gatewayQ
Link : outCObject@gatewayQ outCObject
Link : outSObject@gatewayQ outSObject
Link : registerClient@gatewayQ registerClient

[gatewayQ]
preparation : 00:00:00:010
