# Directories
BINDIR		=	.
SRCDIR		=	src
BUILDDIR	=	build
TESTDIR		=	../
INCLUDE		+=	includes
INCLUDE		+=	$(addprefix $(TESTDIR), $(shell make -s -C $(TESTDIR) get-INCLUDE))
NAME		=	test-avl
TARGET		=	$(BINDIR)/$(NAME)

# Compiler options
CC			=	clang
LIBFLAGS	=	-L$(BUILDDIR) $(subst lib,-l,$(LIBSRC))
CFLAGS		=	$(addprefix -I, $(INCLUDE)) -Wall -Wextra -Werror -g

# Color output
BLACK		=	"\033[0;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[0;34m"
MAGENTA		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[0;37m"
END			=	"\033[0m"

# Source files
SRC			=	$(subst $(SRCDIR)/,,$(wildcard $(SRCDIR)/*.c))

# Libraries
LIBSRC		+=	

OBJECTS		=	$(addprefix $(BUILDDIR)/, $(SRC:%.c=%.o))
LIBS		=	$(addprefix $(BUILDDIR)/, $(addsuffix .a,$(LIBSRC)))

all: $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@[ -d $(BUILDDIR) ] || mkdir $(BUILDDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN)+++ obj: $(YELLOW)$(@F)$(END)

$(BUILDDIR)/%.a: $(LIBDIR)/% $(LIBDIR)/$(LIBSRC)
	@[ -d $(BUILDDIR) ] || mkdir $(BUILDDIR)
	@make -s -C $< > /dev/null
	@cp $</$(@F) $@
	@echo $(GREEN)+++ lib: $(CYAN)$(@F)$(END)

$(TARGET): $(LIBS) $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) -L$(TESTDIR) -lavl
	@echo $(GREEN)+++ bin: $(BLUE)$(NAME)$(END)

$(LIBDIR)/$(LIBSRC):
	@git clone http://github.com/qleguennec/$(@F).git $@
	@cp $@/includes/$(@F).h $(INCLUDE) 2> /dev/null || true

.PHONY: clean
clean:
	@rm $(LIBS) 2> /dev/null && echo $(RED)--- lib: $(CYAN)$(LIBS:$(BUILDDIR)/%=%)$(END); true
	@rm $(OBJECTS) 2> /dev/null && echo $(RED)--- obj: $(YELLOW)$(OBJECTS:$(BUILDDIR)/%=%)$(END); true
	@[ ! "$(ls -A $(BUILDDIR))" ] && rm -r $(BUILDDIR) 2> /dev/null; true

.PHONY:	fclean
fclean: clean
	@rm $(TARGET) 2> /dev/null && echo $(RED)--- bin: $(BLUE)$(NAME)$(END); true
	@rm $(BINDIR)/$(TESTBIN) 2> /dev/null && echo $(RED)--- bin: $(BLUE)$(NAME)$(END); true

.PHONY: re
re: fclean all

.PHONY: test
test: re
	@./test.sh

get-%:
	@echo '$($*)'
