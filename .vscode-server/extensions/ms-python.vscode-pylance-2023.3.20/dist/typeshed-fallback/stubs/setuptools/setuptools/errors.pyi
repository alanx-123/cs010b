from ._distutils.errors import DistutilsError

class RemovedCommandError(DistutilsError, RuntimeError): ...
