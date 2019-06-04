# ReiNX Spoofer

This is a simple service that will mock the `rnx` service on Atmosphere. I have no plans to maintain this and just did it as a fun exercise to play with services and sys-modules on the Switch.

## How to Build

Make sure you have all the submodules necessary to build by running:

```
git submodule update --init --recursive
```

Also make sure you have SimpleIniParser installed, you can find instructions [here](https://github.com/AtlasNX/SimpleIniParser). Once you have all the dependencies installed you can then build libstratosphere by running:

```
cd libstratosphere
make
```

Then you can build ReiNX Spoofer:

```
cd ..
make
```

## How to run DeltaLaunch

Create the following directories on your SD Card:

```
atmosphere/titles/0100000000001000
ReiNX/0100000000001000
```

Extract the DeltaLaunch `exefs.nsp` to `atmosphere/titles/0100000000001000`. Then extract the DeltaLaunch `romfs.bin` file to `ReiNX/0100000000001000`. If/when you switch from not using DeltaLaunch you will need to edit your `loader.ini` file in `atmosphere/` back to the correct `title_id` I suggest making a backup of this file as the service will modify it. I also suggest only running this mock service if you are trying out DeltaLaucnh, as EdiZon and other homebrew may assume you are running ReiNX and produce warnings.
