cmake_minimum_required(VERSION 3.12)
project(ed_qxalg C)

set(CMAKE_C_STANDARD 11)

include_directories(QxdAlg)

add_executable(ed_qxalg
        QxdAlg/main.c
        QxdAlg/qxddefs.h
        QxdAlg/qxdsearching.h
        QxdAlg/qxdsorting.h QxdAlg/qxdvector.h QxdAlg/qxdlist.h QxdAlg/qxdstack.h QxdAlg/qxqueue.h QxdAlg/qxbuffer.h)
