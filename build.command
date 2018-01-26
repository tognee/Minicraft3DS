#!/bin/bash
cd "`dirname $0`"
echo Building 3DSX/ELF/SMDH...
make
echo Creating banner...
`dirname $0`/bannertool makebanner -i icons-banners/banner.png -a icons-banners/audio.wav -o icons-banners/banner.bnr
echo Creating icon...
`dirname $0`/bannertool makesmdh -s "Minicraft3DS" -l "3DS Homebrew port of Notch's ludum dare game 'Minicraft', updated." -p "Davideesk/Andre111/ElijahZAwesome" -i icons-banners/icon.png  -o icons-banners/icon.icn
echo Creating CIA...
`dirname $0`/makerom -f cia -o result/Minicraft3DS.cia -DAPP_ENCRYPTED=false -rsf icons-banners/Minicraft3DS.rsf -target t -exefslogo -elf result/Minicraft3DS.elf -icon icons-banners/icon.icn -banner icons-banners/banner.bnr
echo Creating 3DS/CCI...
`dirname $0`/makerom -f cci -o result/Minicraft3DS.3ds -DAPP_ENCRYPTED=true -rsf icons-banners/Minicraft3DS.rsf -target t -exefslogo -elf result/Minicraft3DS.elf -icon icons-banners/icon.icn -banner icons-banners/banner.bnr