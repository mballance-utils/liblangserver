
cimport libjson_rpc.decl as jrpc

from libcpp.string cimport string as cpp_string
from libcpp.vector cimport vector as cpp_vector
from libcpp.memory cimport unique_ptr
from libcpp cimport bool
from libc.stdint cimport int32_t
cimport cpython.ref as cpy_ref

ctypedef IFactory *IFactoryP

cdef extern from "lls/IFactory.h" namespace "lls":
    cdef cppclass IFactory:
        void init(jrpc.IFactory *jrpc_f)