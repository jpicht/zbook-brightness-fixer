ERRORS=-Wall -Werror -Waddress -Warray-bounds=1 -Wbool-compare -Wc++11-compat -Wc++14-compat -Wchar-subscripts -Wcomment -Wformat -Wint-in-bool-context \
       -Winit-self -Wlogical-not-parentheses -Wmaybe-uninitialized -Wmisleading-indentation -Wmissing-attributes -Wmultistatement-macros -Wnarrowing \
       -Wnonnull -Wnonnull-compare -Wparentheses -Wreorder -Wrestrict -Wreturn-type -Wsequence-point -Wsign-compare \
       -Wsizeof-pointer-div -Wsizeof-pointer-memaccess -Wstrict-aliasing -Wstrict-overflow=1 -Wswitch -Wtautological-compare -Wtrigraphs -Wuninitialized \
       -Wunknown-pragmas -Wunused-function -Wunused-label -Wunused-value -Wunused-variable -Wvolatile-register-var
bright: bright.cpp Makefile
	g++ $(ERRORS) -O3 -o bright bright.cpp
