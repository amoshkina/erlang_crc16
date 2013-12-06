#include "erl_nif.h"
#include "crc.h"

static ERL_NIF_TERM crc16_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
	ErlNifBinary binary;
	int dataSize = 0;
	unsigned char* data = NULL;
	unsigned short crc16 = 0;

	if(!enif_inspect_binary(env, argv[0], &binary)) {
		return enif_make_badarg(env);
	}

	dataSize = binary.size;
	data = binary.data;
	crc16 = CRC16(data, dataSize);

	return enif_make_int(env, crc16);
}

static ErlNifFunc nif_funcs[] = {
    {"crc16", 1, crc16_nif}
};

ERL_NIF_INIT(crc, nif_funcs, NULL, NULL, NULL, NULL)