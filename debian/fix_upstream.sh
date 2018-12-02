#!/bin/sh

# fix_upstream.sh: make a prboom upstream tarball DFSG-compliant
# Copyright (C) 2007 Jon Dowland <jon@alcopop.org>

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# the GNU General Public Licence can be found in
# /usr/share/common-licences/GPL-2 on Debian systems.


set -u
set -e

# fix_upstream.sh: take a prboom tarball as an argument, strip out
# the non-dfsg free stuff.

# requires deutex, sng and imagemagick to be installed

usage() { echo "usage: $0 tarball" >&2; }

if [ $# -ne 1 ]; then
	usage
	exit 1
fi
if [ ! -r "$1" ]; then
	echo "cannot read '$1'" >&2
	exit 1
fi
ORIG="$1"

# orig should be prboom-x.y.z.tar.gz
ORIGRE='prboom-[0-9]\+\.[0-9]\+\.[0-9]\+\.tar\.gz'
if ! echo "$ORIG" | grep -q "$ORIGRE"; then
	echo "input file should match the regexp '$ORIGRE'" >&2
	exit 1
fi
ORIGVERSION=`echo "$ORIG" | sed 's!prboom-\(.*\)\.tar\.gz!\1!'`
DFSGVERSION="$ORIGVERSION+dfsg1"
ORIGDIR=`pwd`
WD=`mktemp -t -d prboom_fix_upstream.XXXXXX`
trapfun() {
	echo "working directory was \"$WD\""
	cd "$ORIGDIR"
}
trap trapfun INT QUIT

CLEANPNG=false
if [ ! -f debian/base.png ]; then
	sng debian/base.sng
	CLEANPNG=true
fi

	cp -p "$ORIG" "$WD"
	ORIG=`basename "$ORIG"`
	cd "$WD"

	tar -xf "$ORIG"
	if [ ! -d "prboom-$ORIGVERSION" ]; then
		echo "the tarball did not unpack to "\
		     "\"prboom-$ORIGVERSION\" as expected" >&2
		exit 1
	fi

		# input files for graphics regeneration

		# we'll assume the input files are in debian/* unless
		# we're already in a directory called debian
		# WD is "debian" in which case
		BASE=base.png 
		BADLUMPS=bad_menu_lumps.txt
		if [ `basename "$ORIGDIR"` != "debian" ]; then
			BADLUMPS="debian/$BADLUMPS"
			BASE="debian/$BASE"
		fi
		BADLUMPS="$ORIGDIR/$BADLUMPS"
		BASE="$ORIGDIR/$BASE"

		mkdir wad
		mv "prboom-$ORIGVERSION/data/prboom.wad" wad/prboom.wad
		mv "prboom-$ORIGVERSION/data/prboom.txt" wad/prboom.txt
		cd wad

		deutex -gif -rgb 0 255 255 -xtract prboom.wad >/dev/null
		# these psuedo-lumps are used as markers in prboom but
		# deutex forgets about them on extract
		touch lumps/{c,b}_{start,end}.lmp

		# remove the DOG resources
		<prboom.txt \
			grep -v DOG  |
			grep -v DSDG \
		>wadinfo.txt

		# substitute the menu graphics with imagemagick
		while read line; do
			set -- $line
			output=$1
			width=$2
			height=$3
			shift 3
			text=`echo "$*" | tr a-z A-Z`

			convert \
				-resize "${width}x${height}!" \
				"$BASE" tmpfile.png

			convert -fill red -font Helvetica-Bold \
				-pointsize 16                  \
				-gravity west                  \
				+antialias                     \
				-draw "text 0,0 '$text'"       \
				tmpfile.png "graphics/$output"


		done < "$BADLUMPS"
		# generate ones

		# repack the wad
		mv prboom.wad prboom.wad.old
		deutex -gif -rgb 0 255 255 -build prboom.wad >/dev/null

		# move the fixed wad back over
		cd ..
		mv wad/prboom.wad "prboom-$ORIGVERSION/data/prboom.wad"
		mv wad/prboom.txt "prboom-$ORIGVERSION/data/prboom.txt"
		rm -r wad

	# repack
	mv "prboom-$ORIGVERSION" "prboom-$DFSGVERSION"
	tar -czf "prboom_$DFSGVERSION.orig.tar.gz" "prboom-$DFSGVERSION"
	rm -r "prboom-$DFSGVERSION"

	rm "$ORIG"

cd "$ORIGDIR"

if [ -n "$CLEANPNG" ]; then
	rm debian/base.png
fi
mv "$WD/prboom_$DFSGVERSION.orig.tar.gz" .
echo "created prboom_$DFSGVERSION.orig.tar.gz"
rmdir "$WD"
