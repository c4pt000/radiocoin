
Debian
====================
This directory contains files used to package radiocoind/radiocoin-qt
for Debian-based Linux systems. If you compile radiocoind/radiocoin-qt yourself, there are some useful files here.

## radiocoin: URI support ##


radiocoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install radiocoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your radiocoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/bitcoin128.png` to `/usr/share/pixmaps`

radiocoin-qt.protocol (KDE)

