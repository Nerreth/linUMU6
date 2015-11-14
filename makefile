all:
		mkdir lib -p
		gcc -fPIC resistance.c -shared -o lib/libresistance.so
		gcc -fPIC component.c -shared -o lib/libcomponent.so
		gcc -fPIC power.c -shared -o lib/libpower.so
		gcc -o electrotest electrotest.c -L./lib -lresistance -lpower -lcomponent -Wl,-rpath,'$$ORIGIN/lib'

lib:
		gcc -fPIC resistance.c -shared -o libresistance.so
		gcc -fPIC component.c -shared -o libcomponent.so
		gcc -fPIC power.c -shared -o libpower.so

install:
		
		mkdir lib -p
		gcc -fPIC resistance.c -shared -o lib/libresistance.so
		gcc -fPIC component.c -shared -o lib/libcomponent.so
		gcc -fPIC power.c -shared -o lib/libpower.so
		gcc -o electrotest electrotest.c -L. -lresistance -lpower -lcomponent
		sudo cp electrotest /usr/bin
		sudo cp lib/* /usr/lib
