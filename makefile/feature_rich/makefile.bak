target         :=  bin
objs           :=  main.o 

CC             :=  gcc
CFLAGS         :=  -Wall -Werror

all: $(target)

deps           :=  $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

bin: $(objs)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEPFLAGS)

clean:
	rm -f $(target) $(objs) $(deps)
