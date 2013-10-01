all:
	g++ -c options.cpp `Magick++-config --cppflags --cxxflags`
	g++ -c term_info.cpp `Magick++-config --cppflags --cxxflags`
	g++ -c asciifier.cpp `Magick++-config --cppflags --cxxflags`
	g++ -c im2a.cpp `Magick++-config --cppflags --cxxflags`
	g++ -o im2a options.o term_info.o asciifier.o im2a.o `Magick++-config --cppflags --cxxflags --ldflags --libs` -lncurses

clean:
	rm *.o im2a
