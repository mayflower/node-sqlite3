#include "sqlite3ext.h"

extern "C" int sqlite3_sqlitereversestring_init(
    sqlite3*d,
    char **pzErrMsg,
    const sqlite3_api_routines *pApi
);

namespace {
    struct Trampoline {
        Trampoline() {
            sqlite3_auto_extension(reinterpret_cast<void(*)()>(sqlite3_sqlitereversestring_init));
        }
    };    
}

namespace extension_trampoline {
    Trampoline t;
}
