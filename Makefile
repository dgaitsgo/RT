# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 14:32:25 by dgaitsgo          #+#    #+#              #
#    Updated: 2017/03/23 18:22:36 by dgaitsgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

SRC_DIR = ./src
OBJ_DIR = ./obs
INC_DIR = ./include

SRC_FILES = \
./src/core/affine_group.c \
./src/core/anti_aliasing.c \
./src/core/bound_entire_scene.c \
./src/core/bounding_box.c \
./src/core/calc_perl_color.c \
./src/core/calc_uv.c \
./src/core/camera.c \
./src/core/cannonical.c \
./src/core/cannonical2.c \
./src/core/color.c \
./src/core/color2.c \
./src/core/cone_inter.c \
./src/core/cone_intersection.c \
./src/core/constructors.c \
./src/core/csg.c \
./src/core/csg2.c \
./src/core/csg_lst.c \
./src/core/csg_ops.c \
./src/core/csg_select.c \
./src/core/cube_intersection.c \
./src/core/cylinder_inter.c \
./src/core/cylinder_intersection.c \
./src/core/draw_bounding_box.c \
./src/core/draw_line.c \
./src/core/event.c \
./src/core/generate_primary_ray.c \
./src/core/geometry.c \
./src/core/get_intersection_color.c \
./src/core/graphics_helpers.c \
./src/core/helpers.c \
./src/core/helpers2.c \
./src/core/inter.c \
./src/core/intersect_bbox.c \
./src/core/intersection.c \
./src/core/light.c \
./src/core/line.c \
./src/core/main.c \
./src/core/material.c \
./src/core/math.c \
./src/core/multithreading.c \
./src/core/multithreading_aa.c \
./src/core/node_util.c \
./src/core/obj_data.c \
./src/core/object.c \
./src/core/perl_noise_tools.c \
./src/core/perlin_noise.c \
./src/core/perlin_noise2.c \
./src/core/phong_shading.c \
./src/core/plane_inter.c \
./src/core/plane_intersection.c \
./src/core/quantize_colors.c \
./src/core/random.c \
./src/core/rasterize.c \
./src/core/refraction.c \
./src/core/render.c \
./src/core/scene.c \
./src/core/screen_shot.c \
./src/core/shader.c \
./src/core/soft_shadow.c \
./src/core/sphere_inter.c \
./src/core/sphere_intersection.c \
./src/core/test_intersection.c \
./src/core/tone_mapping.c \
./src/core/transform.c \
./src/core/transform_bbox.c \
./src/core/triangle_intersection.c \
./src/core/window.c \
./src/matrix/copy_matrix.c \
./src/matrix/inverse_rotation_matrix.c \
./src/matrix/inverse_transformations.c \
./src/matrix/matrix.c \
./src/matrix/matrix_getters.c \
./src/matrix/matrix_utility.c \
./src/matrix/object_matrix_build.c \
./src/matrix/perspective_matrix.c \
./src/matrix/rotation_matrix.c \
./src/matrix/screen_space.c \
./src/matrix/transformation_matrix.c \
./src/mesh/mesh_to_trianlges.c \
./src/mesh/new_mesh.c \
./src/parse/character_check.c \
./src/parse/check_flags.c \
./src/parse/count_words_and_length.c \
./src/parse/file_to_string.c \
./src/parse/flags.c \
./src/parse/get_next_line.c \
./src/parse/only_one_word.c \
./src/parse/parse.c \
./src/parse/parse_camera.c \
./src/parse/parse_csg.c \
./src/parse/parse_element.c \
./src/parse/parse_error.c \
./src/parse/parse_light.c \
./src/parse/parse_material.c \
./src/parse/parse_mesh.c \
./src/parse/parse_mesh2.c \
./src/parse/parse_object.c \
./src/parse/parse_stream_controls.c \
./src/parse/parse_string.c \
./src/parse/parse_texture.c \
./src/parse/parse_tools.c \
./src/parse/parse_transform.c \
./src/parse/parse_triangle.c \
./src/parse/parse_vector_and_scalar.c \
./src/parse/parse_window.c \
./src/parse/remove_white_space.c \
./src/parse/tokenize.c \
./src/vector/vector.c \
./src/vector/vector_basic_ops.c \
./src/vector/vector_basic_ops2.c \
./src/vector/vector_basic_ops3.c \
./src/vector/vector_constructors.c \
./src/vector/vector_min_max.c \
./src/vector/vector_scale.c \
./src/vector/vector_transformations.c \

OBJ_FILES = $(SRC_FILES:.c=.o) #$(addprefix $(OBJ_DIR)/,$(notdir $(SRC_FILES:.c=.o)))

INC_FILES = \
	./include/affine_group.h \
	./include/bounding_box.h \
	./include/camera.h \
	./include/color.h \
	./include/csg.h \
	./include/debug.h \
	./include/enums.h \
	./include/external_headers.h \
	./include/film.h \
	./include/flags.h \
	./include/geometry.h \
	./include/get_next_line.h \
	./include/graphics_helpers.h \
	./include/intersection.h \
	./include/libft.h \
	./include/light.h \
	./include/local_headers.h \
	./include/macros.h \
	./include/maths.h \
	./include/matrix.h \
	./include/mesh.h \
	./include/noise.h \
	./include/obj_data.h \
	./include/object.h \
	./include/parse.h \
	./include/random.h \
	./include/rasterize.h \
	./include/ray.h \
	./include/ray_trace.h \
	./include/refraction.h \
	./include/rt_open_gl.h \
	./include/shader.h \
	./include/shapes.h \
	./include/stats.h \
	./include/texture.h \
	./include/threads.h \
	./include/tile.h \
	./include/tone_map.h \
	./include/transform.h \
	./include/utility.h \
	./include/vector.h \
	./include/window.h \

LIB_DIR = ./lib/libft

FLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C ./lib/libft
	gcc $(FLAGS) -o $(NAME) $(OBJ_FILES) -L$(LIB_DIR) -lft -F/Library/Frameworks -framework SDL2

%.o:%.c $(INC_FILES)
	gcc -c -I$(INC_DIR) $< -o $@

clean:
	make -C ./lib/libft/ clean
	rm -rf $(OBJ_FILES)

fclean: clean
	make -C ./lib/libft/ fclean
	rm -rf $(NAME)

re: fclean all
