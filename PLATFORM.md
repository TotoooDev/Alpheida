# Platforms

## Supporting a new console/platform

If you want the engine to support a new platform, you will need to do the following:

- Create a new folder located in `include/engine/platform/<platform name>` in which you will put all your platform-specific headers.
- Create a new folder located in `src/engine/platform/<platform name>` in which you will put all your platform implementations.
- Add a macro in `include/engine/platform/config.h` to identify the platform you compile for.

Here are all the APIs you will need to implement:

- The `filesystem` API, which declaration is located in `include/engine/platform/fs.h`.
- The `input` API, which declaration is located in `include/engine/platform/input.h`.
- The `platform` API, which declaration is located in `include/engine/platform/platform.h`.
- The `music` API, which declaration is located in `include/engine/music.h`.
- The `sound` API, which declaration is located in `include/engine/sound.h`.
- The `window` API, which declaration is located in `include/engine/graphics/window.h`.
- If your platform doesn't support modern OpenGL rendering, you will also need to [add support for a new graphics API](#supporting-a-new-graphics-api)

## Supporting a new graphics API

The shrimp engine currently only support modern OpenGL rendering.

If you want the engine to support a new graphics API, you will need to do the following:

- Create a new folder located in `include/engine/graphics/<api name>` in which you will put all your graphics API specific headers.
- Create a new folder located in `src/engine/graphics/<api name>` in which you will put all your graphics API implementations.
- Add a macro in `include/engine/graphics/config.h` to identify the graphics API you compile for.

Here are all the APIs you will need to implement:

- The `renderer` API, which declaration is located in `include/engine/graphics/renderer.h`.
- The `texture` API, which declaration is located in `include/engine/graphics/texture.h`.
