#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_makefile_featurerich();

int main()
{
  write_makefile_featurerich();
  return 0;
}

void write_makefile_featurerich()
{
  char filename[] = "makefile_test";
  FILE *fptr = NULL;
  char info[] = "# see "
                "https://github.com/gwu-cs-os/evening_os_hour/blob/master/f19/"
                "10.2-makefiles/03_featureful_makefile/Makefile";
  char binary[] = "BINARY=bin";
  char codedirs[] = "CODEDIRS=. ./src # source files";
  char incdirs[] = "INCDIRS=. ./header # can be list of headers";
  char compiler[] = "CXX=g++";
  char opts_debug[] = "OPT_DEBUG=-O0";
  char opts_release[] = "OPT_RELEASE=-O2";
  char comment_header_dependency[] =
      "# generate files that encode make rules for the .h dependencies";
  char depflags[] = "DEPFLAGS=-MP -MD";
  char comment_autoinclude_incdirs[] = "# automatically add the -I onto each include directory";
  char cxxflags_debug[] = "CXXFLAGS_DEBUG=-Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) "
                          "$(OPT_DEBUG) $(DEPFLAGS)";
  char cxxflags_release[] =
      "CXXFLAGS_RELEASE=-Wall -Wextra $(foreach D,$(INCDIRS),-I$(D)) $(OPT_RELEASE) $(DEPFLAGS)";
  char ldflags[] = "LDFLAGS= # math: -lm | ncurses: -lncurses -ltinfo -lmenu";
  char comment_regular_expression_completion_c_sources[] =
      "# for-style iteration (foreach) and regular expression completions "
      "(wildcard)";
  char cfiles[] = "CXXFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))";
  char comment_regex_replacement[] = "# regular expression replacement";
  char objs[] = "OBJECTS=$(patsubst %.cpp,%.o,$(CXXFILES))";
  char depfiles[] = "DEPFILES=$(patsubst %.cpp,%.d,$(CXXFILES))";
  char build_all[] = "all: $(BINARY)";
  char build_binaries[] = "$(BINARY): $(OBJECTS)";
  char build_binaries_recipe[] = "$(CXX) -o $@ $^ $(LDFLAGS)";
  char comment_c_dependency[] = "# only want the .c file dependency here, thus $< instead of $^.";
  char build_objs[] = "%.o:%.cpp";
  char build_objs_recipe_debug[] = "$(CXX) $(CXXFLAGS_DEBUG) -c -o $@ $<";
  // char build_objs_recipe_release[] = "$(CXX) $(CXXFLAGS_RELEASE) -c -o $@ $<";
  char cleanup[] = "clean:";
  char cleanup_recipe[] = "rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)";
  char comment_shell_cmds[] = "# shell commands are a set of keystrokes away";
  char distribute[] = "distribute: clean";
  char distribute_recipe[] = "tar -cJvf dist.tar.xz *";
  char comment_silence_printing[] = "# @ silences the printing of the command";
  char comment_silence_printing_syntax[] = "# $(info ...) prints output";
  char diff[] = "diff:";
  char diff_recipe_one[] = "$(info The status of the repository, and the volume "
                           "of per-file changes:)";
  char diff_recipe_two[] = "@git status";
  char diff_recipe_three[] = "@git diff --stat";
  char comment_include_dependencies[] = "# include the dependencies";
  char include_dependencies[] = "-include $(DEPFILES)";
  char comment_add_phony[] = "# add .PHONY so that the non-targetfile - rules "
                             "work even if a file with the same name exists.";
  char add_phony[] = ".PHONY: all clean distribute diff";

  if ((fptr = fopen(filename, "w")) == NULL)
  {
    // fopen returned NULL ==> file could not be opened because of an error, see
    // man fopen
    fprintf(stderr, "ERROR: opening file failed! Filename: %s | error code: %s!\n", filename,
            strerror(errno));
    exit(EXIT_FAILURE);
  }
  else
  {
    fprintf(fptr, "%s\n\n", info);
    fprintf(fptr, "%s\n", binary);
    fprintf(fptr, "%s\n", codedirs);
    fprintf(fptr, "%s\n\n", incdirs);
    fprintf(fptr, "%s\n", compiler);
    fprintf(fptr, "%s\n", opts_debug);
    fprintf(fptr, "%s\n", opts_release);
    fprintf(fptr, "%s\n", comment_header_dependency);
    fprintf(fptr, "%s\n", depflags);
    fprintf(fptr, "%s\n", comment_autoinclude_incdirs);
    fprintf(fptr, "%s\n", cxxflags_debug);
    fprintf(fptr, "%s\n", cxxflags_release);
    fprintf(fptr, "%s\n\n", ldflags);
    fprintf(fptr, "%s\n", comment_regular_expression_completion_c_sources);
    fprintf(fptr, "%s\n", cfiles);
    fprintf(fptr, "%s\n", comment_regex_replacement);
    fprintf(fptr, "%s\n", objs);
    fprintf(fptr, "%s\n\n", depfiles);
    fprintf(fptr, "%s\n\n", build_all);
    fprintf(fptr, "%s\n", build_binaries);
    fprintf(fptr, "\t%s\n\n", build_binaries_recipe);
    fprintf(fptr, "%s\n", comment_c_dependency);
    fprintf(fptr, "%s\n", build_objs);
    fprintf(fptr, "\t%s\n\n", build_objs_recipe_debug);
    // fprintf(fptr, "\t%s\n\n", build_objs_recipe);
    fprintf(fptr, "%s\n", cleanup);
    fprintf(fptr, "\t%s\n\n", cleanup_recipe);
    fprintf(fptr, "%s\n", comment_shell_cmds);
    fprintf(fptr, "%s\n", distribute);
    fprintf(fptr, "\t%s\n\n", distribute_recipe);
    fprintf(fptr, "%s\n", comment_silence_printing);
    fprintf(fptr, "%s\n\n", comment_silence_printing_syntax);
    fprintf(fptr, "%s\n", diff);
    fprintf(fptr, "\t%s\n", diff_recipe_one);
    fprintf(fptr, "\t%s\n", diff_recipe_two);
    fprintf(fptr, "\t%s\n\n", diff_recipe_three);
    fprintf(fptr, "%s\n", comment_include_dependencies);
    fprintf(fptr, "%s\n\n", include_dependencies);
    fprintf(fptr, "%s\n", comment_add_phony);
    fprintf(fptr, "%s\n", add_phony);
    fclose(fptr);
  }
}
