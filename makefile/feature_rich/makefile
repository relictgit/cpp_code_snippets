target         :=  bin
objs           :=  main.o 

CXX            :=  g++
CXXFLAGS       :=  -Wall -Werror -Wextra -Wshadow

all: $(target)

deps           :=  $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

bin: $(objs)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< $(DEPFLAGS)

clean:
	rm -f $(target) $(objs) $(deps)
