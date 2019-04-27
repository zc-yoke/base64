OBJS=decode.o encode.o

all: static_lib shared_lib static_app shared_app

static_lib:$(OBJS)
	ar -rc libbase64.a $(OBJS)
	
shared_lib:$(OBJS)
	g++ -shared -o base64.dll $(OBJS)

static_app:
	g++ test.cpp -Wall -static -o base64_static  -L. -I. -lbase64
	
shared_app:
	g++ test.cpp -o student_shared -I.  -L. base64.dll
	
decode.o: b64.h decode.c
	gcc -c b64.h decode.c

encode.o: b64.h encode.c
	gcc -c b64.h encode.c
	
.PHONY:clean cleanall
clean:
	rm -f *.o *.gch
cleanall:
	rm -f *. *.exe *.a *.dll *.so *.gch

