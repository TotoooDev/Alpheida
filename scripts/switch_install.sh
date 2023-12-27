#!/bin/bash

# parameters
IP=192.168.1.21
PORT=5000
USER=toto
PASS=pass

# actual script
cd ..
ftp -i -n $IP $PORT << END_SCRIPT
quote USER $USER
quote PASS $PASS
cd switch
delete Alpheida.nro
rmdir Alpheida
mkdir Alpheida
mkdir Alpheida/images
send bin/Alpheida.nro Alpheida.nro
send assets/images/pp.jpg Alpheida/images/pp.jpg
END_SCRIPT

