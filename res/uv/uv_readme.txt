The process of creating uv information to use it later for pixel animations :

1) The uv's are mapped using blender.
2) The model is exported as .obj file.
3) Raw uv data is extracted from the model.
4) UV data is first rounded to the nearest pixel using uv_round.cpp
5) UV data is then grouped in to bunches of 4 uv coords and then reordered to mach our coord system using uv_bunch.cpp
6) The bunches of uv's are then sorted in acending order using uv_sort.cpp