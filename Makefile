all: crc

crc:
	./rebar compile

clean:
	./rebar clean
	rm -rf priv ebin
