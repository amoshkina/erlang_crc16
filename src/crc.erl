-module(crc).
-export([crc16/1]).
-on_load(init/0).

init() ->
  ok = erlang:load_nif("./priv/crc_nif", 0).

crc16(_Data) ->
  erlang:nif_error(nif_library_not_loaded).