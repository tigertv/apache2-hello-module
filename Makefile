.PHONY: clean 

mod_hello.la: mod_hello.c
	apxs -c $<
install: mod_hello.la hello.conf hello.load
	sudo apxs -i mod_hello.la
	sudo cp hello.conf hello.load /etc/apache2/mods-available/
	sudo a2enmod hello
	sudo service apache2 restart
clean: 
	rm -rf .libs *.la *.lo *.slo
