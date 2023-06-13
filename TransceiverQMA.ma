[top]
components : transQ@Transqueue
in : inApp inGateway position done
out : outCObject outSObject location
Link : inApp inApp@transQ
Link : inGateway inGateway@transQ
Link : position position@transQ
Link : done done@transQ
Link : outCObject@transQ outCObject
Link : outSObject@transQ outSObject
Link : location@transQ location

[transQ]
preparation : 00:00:00:010
