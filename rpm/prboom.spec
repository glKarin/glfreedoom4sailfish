Name:		prboom
Version:	2.5.0harmattan1
Release:	1
Summary: Doom - classic 3D shoot-em-up game. OpenGL PrBoom + FreeDOOM

Vendor: karin <beyondk2000@gmail.com>
Packager: karin <beyondk2000@gmail.com>
Group:		Amusements/Games
License:	GPL
URL:		https://github.com/glKarin/glfreedoom4sailfish
Source0:	%{name}.tar.gz
BuildRoot:	%(mktemp -ud %{name})

BuildRequires:	pkgconfig(glesv1_cm)
BuildRequires:	pkgconfig(audioresource)
BuildRequires:	pkgconfig(glib-2.0)
BuildRequires:	pkgconfig(sdl2)
BuildRequires:	SDL2_mixer-devel, SDL2_net-devel
Requires:	libhybris-libGLESv1
Requires:	libaudioresource
Requires:	SDL2, SDL2_net, SDL2_mixer
Requires:	glib2

%description
Doom is the classic 3D shoot-em-up game. It must have been one of the best
selling games ever; it totally outclassed any  3D world games that preceded
it, with amazing speed, flexibility, and outstanding gameplay. The specs to
the game were released, and thousands of extra levels were written by fans of
the game; even today new levels are written for Doom faster then any one person
could play them. 

%define get_arch %(uname -m | sed -e s/i.86/i386/ -e s/sun4u/sparc/ -e s/sparc64/sparc/ -e s/arm.*/arm/ -e s/sa110/arm/ -e s/alpha/axp/)

%prep
%setup -q -n %{name}


%build
%configure --prefix=/usr --mandir=/usr/share/man --disable-cpu-opt --disable-dogs --disable-i386-asm LDFLAGS="-Wl,--as-needed -Wl,-z,defs" --with-waddir=/usr/share/prboom/iwad
make


%install
rm -rf $RPM_BUILD_ROOT
# binary
install -D -m 755 src/prboom $RPM_BUILD_ROOT/usr/bin/prboom
install -D -m 755 src/prboom-game-server $RPM_BUILD_ROOT/usr/bin/prboom-game-server
# desktop
install -D -m 644 debian/prboom+freedoom.desktop $RPM_BUILD_ROOT/usr/share/applications/prboom+freedoom.desktop
install -D -m 644 debian/prboom+freedoom1.desktop $RPM_BUILD_ROOT/usr/share/applications/prboom+freedoom1.desktop
install -D -m 644 debian/prboom+freedoom2.desktop $RPM_BUILD_ROOT/usr/share/applications/prboom+freedoom2.desktop
install -D -m 644 prboom_80.png $RPM_BUILD_ROOT/usr/share/icons/hicolor/80x80/apps/prboom_80.png
# resource
mkdir -p $RPM_BUILD_ROOT/usr/share/prboom/resc
install -D -m 644 resc/*.png $RPM_BUILD_ROOT/usr/share/prboom/resc
# wad files
mkdir -p $RPM_BUILD_ROOT/usr/share/prboom/iwad
install -D -m 644 freedoom/*.wad $RPM_BUILD_ROOT/usr/share/prboom/iwad
install -D -m 644 data/prboom.wad $RPM_BUILD_ROOT/usr/share/prboom/iwad
# timidity
mkdir -p $RPM_BUILD_ROOT/usr/local/lib/timidity
install -D -m 644 timidity/timidity.cfg $RPM_BUILD_ROOT/usr/local/lib/timidity
install -D -m 644 timidity/README $RPM_BUILD_ROOT/usr/local/lib/timidity
install -D -m 644 timidity/copyright.txt $RPM_BUILD_ROOT/usr/local/lib/timidity
mkdir -p $RPM_BUILD_ROOT/usr/local/lib/timidity/instruments
install -D -m 755 timidity/instruments/* $RPM_BUILD_ROOT/usr/local/lib/timidity/instruments


%clean
make clean
rm -rf $RPM_BUILD_ROOT


%files
%defattr(-,root,root,-)
%doc
/usr/share/prboom/iwad
/usr/share/prboom/resc
/usr/local/lib/timidity
/usr/share/applications/prboom+freedoom.desktop
/usr/share/applications/prboom+freedoom1.desktop
/usr/share/applications/prboom+freedoom2.desktop
/usr/share/icons/hicolor/80x80/apps/prboom_80.png
/usr/bin/prboom
/usr/bin/prboom-game-server



%changelog
* Sat Dec 1 2018 Karin Zhao <beyondk2000@gmail.com> - 2.5.0harmattan1
	* OpenGL rendering.
	* Add pitch-rotation.
	* Add freedoom1.wad and freedoom2.wad.
	* Add timidity files in /usr/local/lib/ for midi music playing.

%post


%preun
