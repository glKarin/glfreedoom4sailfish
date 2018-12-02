#! /bin/sh
# prerm script for prboom

set -e

case "$1" in
    remove)
        update-alternatives --remove doom /usr/games/prboom
        ;;
    upgrade|deconfigure|failed-upgrade)
        ;;
    *)
        echo "prerm called with unknown argument \`$1'" >&2
        exit 1
    ;;
esac

#DEBHELPER#

exit 0
