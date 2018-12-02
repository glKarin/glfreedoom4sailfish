#! /bin/sh

# MAEMO 
gtk-update-icon-cache -f /usr/share/icons/hicolor
chown user /opt/doom/wads

# postinst script for prboom

set -e

case "$1" in
    configure|abort-upgrade)
    update-alternatives --install /usr/games/doom \
                                  doom \
                                  /usr/games/prboom \
                                  50
    ;;

    abort-remove|abort-deconfigure)

    ;;

    *)
        echo "postinst called with unknown argument \`$1'" >&2
        exit 1
    ;;
esac

#DEBHELPER#

exit 0
