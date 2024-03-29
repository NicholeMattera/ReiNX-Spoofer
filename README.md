# ReiNX Spoofer

This is a simple service that will mock the `rnx` and `tx` service on Atmosphere. I have no plans to maintain this and just did it as a fun exercise to play with services and sys-modules on the Switch. Running this service may cause some apps to produce warnings about running ReiNX.

## How to Build

Make sure you have all the submodules necessary to build by running:

```
git submodule update --init --recursive
```

Then you can build ReiNX Spoofer:

```
make
```

## How to run DeltaLaunch (June 6th Release)

DeltaLaunch will now run natively on Atmosphere. If for some reason you wish to run it on Atmosphere as if you were running it on ReiNX then you can do the following. Create the following directories on your SD Card:

```
atmosphere/titles/0100000000001000
ReiNX/sysmodules
ReiNX/titles/0100000000001000
```

Extract the DeltaLaunch `exefs.nsp` to `atmosphere/titles/0100000000001000`. Then extract the DeltaLaunch `romfs.bin` file to `ReiNX/titles/0100000000001000`. You need to add a blank file named `loader.kip` into the `ReiNX/sysmodules` folder. If/when you switch from not using DeltaLaunch you will need to edit your `loader.ini` file in `atmosphere/` back to the correct `title_id` I suggest making a backup of this file as the service will modify it.

## How to run DeltaLaunch (June 3rd Release)

Create the following directories on your SD Card:

```
atmosphere/titles/0100000000001000
ReiNX/titles/0100000000001000
```

Extract the DeltaLaunch `exefs.nsp` to `atmosphere/titles/0100000000001000`. Then extract the DeltaLaunch `romfs.bin` file to `ReiNX/titles/0100000000001000`. If/when you switch from not using DeltaLaunch you will need to edit your `loader.ini` file in `atmosphere/` back to the correct `title_id` I suggest making a backup of this file as the service will modify it.
