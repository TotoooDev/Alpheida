#!/bin/bash

# parameters
IP=192.168.1.23
PORT=5000
USER=host
PASS=cool_password

# actual script
ftp -i -n $IP $PORT << END_SCRIPT
quote USER $USER
quote PASS $PASS
binary
cd switch
delete Alpheida/Alpheida.nro
send bin/Alpheida.nro Alpheida/Alpheida.nro
END_SCRIPT

