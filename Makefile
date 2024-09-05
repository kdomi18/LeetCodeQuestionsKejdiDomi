app = TestTreeNode
# compiler
CC = /usr/bin/clang++

# compiler flags with errors
CPPFLAGS = -stdlib=libc++ -g -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror -std=c++20

# compiler flags no errors
#CPPFLAGS = -stdlib=libc++ -g -std=c++20

# all source files
srcfiles := $(app).cpp

# create executable
build: $(srcfiles)
	@$(CC) $(CPPFLAGS) $(srcfiles) -o $(app) 

# cleanup
clean:
	@rm -rf $(app).dSYM $(app)
	
