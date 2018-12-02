#/bin/bash

case $1 in
	configure)
	./configure --prefix=/usr --mandir=\$${prefix}/share/man --disable-cpu-opt --disable-dogs \
		--disable-i386-asm # --disable-gl	
	LDFLAGS="-Wl,--as-needed -Wl,-z,defs" #--with-waddir=\$${prefix}/share/prboom+freedoom
#	--disable-cpu-opt
#	--host=$(DEB_HOST_GNU_TYPE) --target=$(DEB_BUILD_GNU_TYPE) \
	;;
	make)
		make
		;;
	run)
		;;
esac
