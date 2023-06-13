[top]
components : serv@CPU
components : serverQueue@Queue
in : inC
out : outS
Link : inC in@serverQueue
Link : out@serverQueue in@serv
Link : out@serv outS
Link : out@serv done@serverQueue

[serverQueue]
preparation : 00:00:00:010

[serv]
distribution : normal
mean : 10
deviation : 2
