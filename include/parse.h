/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:04:40 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 18:15:20 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSE_H
# define __PARSE_H
# include "libft.h"
# include "get_next_line.h"
# include "ray_trace.h"
# include "flags.h"

enum	e_elements
{
	EMPTY_ELEM = 0,
	WINDOW_ELEM = 8,
	CAMERA_ELEM = 10,
	LIGHT_ELEM = 11,
	CSG_ELEM = 12,
};

enum	e_max_elements
{
	MAX_TEXTURE_ELEMENTS = 7,
	MAX_WINDOW_ELEMENTS = 2,
	MAX_FILM_ELEMENTS = 1,
	MAX_CAMERA_ELEMENTS = 5,
	MAX_TRANSFORM_ELEMENTS = 3,
	MAX_MATERIAL_ELEMENTS = 7,
	MAX_PLANE_ELEMENTS = 3,
	MAX_SPHERE_ELEMENTS = 3,
	MAX_CYLINDER_ELEMENTS = 5,
	MAX_MESH_ELEMENTS = 4,
	MAX_CUBE_ELEMENTS = 4,
	MAX_TRIANGLE_ELEMENTS = 3,
	MAX_CONE_ELEMENTS = 5,
	MAX_LIGHT_ELEMENTS = 4,
	MAX_SCENE_LIGHTS = 1,
	MAX_CSG_ELEMENTS = 2,
};

enum	e_parse_errors
{
	BAD_FILE = 200,
	UNDERDETERMINED = 201,
	UNKNOWN_ELEMENT = 202,
	BAD_FORM = 203,
	DEGENERATE_SHAPE = 204,
	TOO_MANY_OBJECTS = 205,
	TOO_MANY_LIGHTS = 206,
	UNEXPECTED_SYMBOL = 207,
	REPEAT_SYMBOL = 208,
	CONFLICTING_IDS = 209,
	DEGENERATE_VALUE = 210,
	MEMORY_ERROR = 211,
	TEXTURE_ERROR = 212,
	CAMERA_UNDEFINED = 401,
	NO_OBJECTS = 402,
	NO_LIGHTS = 403,
	DENSE_SCENE = 404,
};

void	load_obj(t_obj_data *od, const int fd);
void	reset_counter(t_obj_data *od);
int		string_to_shape(char **tokens, int *i);
int		check_flag(int *flag_location, int flag);
void	set_flag(int *flag_location, int flag);
int		check_repeat(int *flag_location, int test_flag);
void	parse_window(char **tokens, int *i, t_window *window, int max_depth);
void	parse_light(char **tokens, int *i, int max, t_scene *scene);
void	parse_element_container(char **tokens, int *i,
		t_scene *scene, int element);
int		element(char **tokens, int *i, t_scene *scene);
int		parse_scene(char **tokens, t_scene *scene);
void	parse_camera(char **tokens, int *i, t_camera *camera, int max);
void	parse_material_container(char **tokens, int *i, t_material *field);
void	parse_material(char **tokens, int *i, t_material *field, int max_depth);
int		max_elements(int type);
void	parse_mesh(char **tokens, int *i, t_scene *scene, int max_depth);
void	parse_plane_fields(char **tokens, int *i, t_plane *plane);
void	parse_sphere_fields(char **tokens, int *i, t_sphere *sphere);
void	parse_cylinder_fields(char **tokens, int *i, t_cylinder *cylinder);
void	parse_cone_fields(char **tokens, int *i, t_cone *cone);
void	parse_object_fields(char **tokens, int *i, t_object *object);
void	parse_primitive(char **tokens, int *i, t_object *object, int max_depth);
void	parse_triangle(char **tokens, int *i, t_object *object, int max_depth);
void	parse_transform(char **tokens, int *i,
						t_transform *field, int max_depth);
void	parse_transform_container(char **tokens, int *i, t_transform *field);
void	parse_texture(char **tokens, int *i, t_texture *field);
void	parse_double(char *token, double *field, double min, double max);
void	parse_int(char *token, int *field, int min, int max);
void	parse_double_container(char **tokens, int *i,
								double *field, t_range range);
void	parse_int_container(char **tokens, int *i, int *field, t_range range);
void	parse_vector(char **tokens, int *i, t_vector *field, t_range range);
int		accept(char *candidate, char *expected, int *i);
int		check(char *candidate, char *possibility);
int		expect(char *candidate, char *expected, int *i);
int		next(char **tokens, char *candidate, int *i);
char	**tokenize(char *s);
int		count_words_and_length(char *s, int length_table[1000]);
int		is_space(char c);
int		lower_case_letter(char c);
int		capital_letter(char c);
int		is_digit(char c);
int		balancing_symbol(char c);
char	*first_word(char *s);
int		only_spaces(char *s);
int		only_one_word(char *s);
int		in_comments(char *s);
char	*file_to_string(const int fd);
char	*append(char *s, char *to_add);
void	cut_word_from(int *i, int *beg, int *end, char *s);
char	*remove_white_spaces(char *s);
int		parse_warning(int error);
int		parse_error(int error, char **tokens, int *i);
void	parse_csg(char **tokens, int *i, t_node *field, int max_depth);
void	is_csg(char **tokens, int *i, t_node *field);
void	parse_csg_container(char **tokens, int *i, t_node *field);

#endif
