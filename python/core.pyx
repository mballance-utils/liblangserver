
import os
import ctypes
from libcpp.vector cimport vector as cpp_vector
from libc.stdint cimport intptr_t
cimport libjson_rpc.core as jrpc
cimport libjson_rpc.decl as jrpc_decl
from lls cimport decl as lls_decl


cdef class Factory(object):

    def __init__(self):
        pass

    cpdef void init(self, jrpc.Factory jrpc_f):
        cdef jrpc_decl.IFactory *hndl = NULL
        cdef lls_decl.IFactory *f = NULL
        f = self._hndl
        f.init(hndl)
        hndl = jrpc_f._hndl
        self._hndl.init(hndl)

    @staticmethod
    def inst():
        cdef lls_decl.IFactory *hndl = NULL
        cdef Factory factory
        global _inst

        if _inst is None:
            ext_dir = os.path.dirname(os.path.abspath(__file__))

            build_dir = os.path.abspath(os.path.join(ext_dir, "../../build"))

            # First, look in the build directory
            core_lib = None

            # TODO: check already-loaded libraries for libdebug-mgr symbols?
            libname = "liblangserver.so"
            # for libdir in ("lib", "lib64"):
            #     if os.path.isfile(os.path.join(build_dir, libdir, libname)):
            #         core_lib = os.path.join(build_dir, libdir, libname)
            #         break
            if core_lib is None:
                core_lib = os.path.join(ext_dir, libname)

            if not os.path.isfile(core_lib):
                raise Exception("Extension library core \"%s\" doesn't exist" % core_lib)

            so = ctypes.cdll.LoadLibrary(core_lib)

            func = so.lls_getFactory
            func.restype = ctypes.c_void_p

            hndl_v = func()
            hndl = <lls_decl.IFactoryP>(<intptr_t>(hndl_v))

            factory = Factory()
            factory._hndl = hndl
            jrpc_f = jrpc.Factory.inst()

            factory.init(jrpc_f)

            _inst = factory

        return _inst

_inst = None
