
import ctypes
cimport libjson_rpc.core as jrpc
cimport lls.decl as lls_decl
from libcpp cimport bool
from libc.stdint cimport int32_t

cdef class Factory(object):
    cdef lls_decl.IFactory    *_hndl

    cpdef void init(self, jrpc.Factory jrpc_f)
