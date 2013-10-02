
# im2a

An image to ASCII converter, made for 256-color terminals.

The idea came after [jp2a](http://csl.sublevel3.org/jp2a/) for its lack of 256-color terminal support and its JPEG format restriction.

## Dependencies

[ImageMagick](http://www.imagemagick.org/) - a great library for image manipulation. Chances are you already have it installed.

## Installation on Mac OSX

If you're using [Homebrew](http://brew.sh/) just type this in your terminal:

``` bash
brew install https://raw.github.com/tzvetkoff/im2a/master/misc/im2a.rb
```

## Installation on other *nix platforms

Depending on your distro, you'll have to install ImageMagick on your own.

For ArchLinux just type:

``` bash
sudo pacman -S imagemagick
```

For Ubuntu:

``` bash
sudo apt-get install build-essential imagemagick libmagick++-dev
```

After you've installed ImageMagick and the development libraries, get the sources and compile them:

``` bash
git clone git://github.com/tzvetkoff/im2a.git
cd im2a
make
sudo cp im2a /usr/local/bin
```

That's it.

## License

```
"THE BEER-WARE LICENSE" (Revision 42):
<Latchezar Tzvetkoff> wrote this file. As long as you retain this notice you
can do whatever you want with this stuff. If we meet some day, and you think
this stuff is worth it, you can buy me a beer in return. Latchezar Tzvetkoff
```
