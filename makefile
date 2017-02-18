SUBDIRS = src
rshell: all
	-mkdir bin/
	for dir in $(SUBDIRS); do \
		cd $$dir; \
		mv rshell ../bin; \
		#cd -; \
	done
all: 
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
		#cd -;\
	done