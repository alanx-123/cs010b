from _typeshed import Incomplete
from typing import Any

JSON_OID: int
JSONARRAY_OID: int
JSONB_OID: int
JSONBARRAY_OID: int

class Json:
    adapted: Any
    def __init__(self, adapted, dumps: Incomplete | None = ...) -> None: ...
    def __conform__(self, proto): ...
    def dumps(self, obj): ...
    def prepare(self, conn) -> None: ...
    def getquoted(self): ...

def register_json(
    conn_or_curs: Incomplete | None = ...,
    globally: bool = ...,
    loads: Incomplete | None = ...,
    oid: Incomplete | None = ...,
    array_oid: Incomplete | None = ...,
    name: str = ...,
): ...
def register_default_json(conn_or_curs: Incomplete | None = ..., globally: bool = ..., loads: Incomplete | None = ...): ...
def register_default_jsonb(conn_or_curs: Incomplete | None = ..., globally: bool = ..., loads: Incomplete | None = ...): ...
