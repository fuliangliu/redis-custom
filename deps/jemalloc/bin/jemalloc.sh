#!/bin/sh

prefix=/opt/src/jemalloc-3.6.0/library
exec_prefix=/opt/src/jemalloc-3.6.0/library
libdir=${exec_prefix}/lib

LD_PRELOAD=${libdir}/libjemalloc.so.1
export LD_PRELOAD
exec "$@"
