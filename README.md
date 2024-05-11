# wipeoutPD

A Playdate port of [wipeout-rewrite](https://github.com/phoboslab/wipeout-rewrite) by [phoboslab](https://github.com/phoboslab)

So far, it is hard-coded to show the attract mode for one ship on a time trial. All graphics are drawn in a simple wireframe mode.

⚠️ Work in progress. Expect bugs.


# Screenshots

![Time Trial](/Screenshots/wipeoutPD-timetrial.gif?raw=true) ![Scenery Off](/Screenshots/wipeoutPD-screen1.png?raw=true)


# Assets

This repository does not contain the assets (textures, 3D models etc.) needed to run the game. See [wipeout-rewrite README.md](https://github.com/phoboslab/wipeout-rewrite/blob/master/README.md#running) for more details.

Assets should be placed in the `/Source` directory, for example:

```
./Source/Track01.wav # optional background music
./Source/wipeout/common/allsh.prm # ships
./Source/wipeout/common/alcol.prm # collision
./Source/wipeout/track06/track.trv # track 06 vertices
./Source/wipeout/track06/track.trf # track 06 faces
./Source/wipeout/track06/track.trs # track 06 sections
./Source/wipeout/track06/scene.prm # track 06 surrounding scenery
```

## Creating an Audio Track
Example: from `input.mp3`

`ffmpeg -i input.mp3 -acodec adpcm_ima_wav Track01.wav`


# Building
## Windows
### Build Playdate Simulator + Visual Studio
`mkdir build`
`cd build`
`cmake ..`
You need to install clang: https://learn.microsoft.com/en-us/cpp/build/clang-support-msbuild?view=msvc-170
In visual studio:
- In the Solutions Explorer within Visual Studio, select the target with the project name, not a meta target.
- Right-click and select "Set as Startup Project"
- Solution Explorer->wipeout->(right click)->properties->General->Platform Toolset-> LLVM (clang-cl)


### Build Playdate Device:
`cmake .. -G "MinGW Makefiles" --toolchain=C:/develop/PlaydateSDK/C_API/buildsupport/arm.cmake`
then
`cmake --build .`
or optionally:
`cmake --build . --config Release`
or
`cmake --build . --config Debug`


## Nova
Use the integrated Playdate Simulator Tasks for building and running

## Linux / Mac OS
Use the `make` command to create a wipeout.pdx bundle. See section on *Assets* above

# License - same as [wipeout-rewrite](https://github.com/phoboslab/wipeout-rewrite/blob/master/README.md#license)

There is none.

This code can NOT be used to make a commercial release of Wipeout for Playdate. It is intended only for building and running  on your own simulator or device.
See [wipeout-rewrite README.md](https://github.com/phoboslab/wipeout-rewrite/blob/master/README.md#license) for details

