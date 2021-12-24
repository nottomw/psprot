cmake_minimum_required(VERSION 2.8)

add_library(vector_template STATIC
    vector_template.c
)

add_library(vector_template::vector_template ALIAS vector_template)
