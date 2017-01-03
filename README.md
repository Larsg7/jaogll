[![Build Status](https://travis-ci.org/Larsg7/jaogll.svg?branch=travis)](https://travis-ci.org/Larsg7/jaogll) [![Version](https://img.shields.io/badge/version-v0.1--alpha-blue.svg)](https://github.com/Larsg7/jaogll/releases)

# JAOGLL

JAOGLL - just another OpenGL library (_you know, naming is hard_) - is my personal small OpenGL library and game engine. It is still in heavy development and uses SDL2 as its window and input manager.

I would not advise anybody to use it, as it is pretty unfinished, unpolished and not well documented (all of that might change in the future).

But if you want, here are the instructions:

## Dependencies

You need to have SDL2, OpenGL and Glew in addition to g++ with c++11 support installed.

## Installation

```
    make
    sudo make install
```

## Usage

To compile your program run `g++ source-files -lSDL2 -lGL -lGLEW -ljaogll`.
Documentation is in the works (a bit...maybe).

## Acknowledgements

 * Youtube series by [MakingGamesWithBen](https://www.youtube.com/user/makinggameswithben).
 * Numerous online tutorials including:
    * http://www.opengl-tutorial.org/
    * https://open.gl/
    * https://learnopengl.com/

## License

This program is published under the GNU General Public License v3.0.