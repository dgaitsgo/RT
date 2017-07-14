/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:46:03 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/19 15:08:19 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RAY_TRACE_H
# define __RAY_TRACE_H

# include "external_headers.h"
# include "local_headers.h"
# include "ray.h"

typedef struct				s_scene
{
	int						flags;
	int						n_objects;
	int						n_lights;
	t_inter					(*intersect_fn_pointers[4])(t_ray t, t_object *i);
	t_stats					stats;
	t_mesh					*mesh;
	t_light					**light;
	t_matrix				projection;
	t_matrix				screen_space;
	t_object				*last;
	t_object				*root_object;
	t_bbox					bbox;
	t_vector				*box_container;
	t_camera				camera;
	t_window				window;
	unsigned char			hash[512];
}							t_scene;

void						free_obj_data_mem(t_obj_data *od);
void						poll_events(t_scene *scene);
t_vector					cylinder_normal(t_vector point, int hit);
void						fill_inter(t_intersection *i,
								t_object *object, t_ray ray);
t_intersection				process_intersection(t_ray world_ray,
								t_object *object,
							t_inter (*fn_intersect_object)(t_ray, t_object *));
void						put_image(t_scene *scene);
t_uv						calc_sphere_uv(t_intersection *intersection);
t_uv						calc_plane_uv(t_intersection *intersection);
t_uv						calc_cylinder_uv(t_intersection *intersection);
t_uv						calc_cone_uv(t_intersection *intersection);
void						draw_all_bounding_boxes(t_scene *scene);
void						draw_bbox(t_vector *box,
								t_bbox bbox, t_scene *scene);
void						draw_line(t_line line, t_vector color,
								t_window *window);
void						screen_shot(t_scene *scene);
void						transform_and_push_mesh(t_scene *scene,
							t_obj_data *od,
								t_affine_group *ag, t_bbox mesh_bbox);
void						push_triangles(t_scene *scene, t_mesh *mesh);
t_ray						generate_primary_ray(t_camera *camera,
								double x, double y);
void						draw_scene_bbox(t_scene *scene);
void						bound_entire_scene(t_scene *scene);
void						free_if(void *ptr);
int							key_to_event(int keycode, t_scene *scene);
void						destroy_scene(t_scene *scene);
t_vector					*shader(t_intersection intersection,
									t_scene *scene,
									t_vector *color,
									int depth);
void						phong_shading(t_vector *color,
								t_intersection intersection,
								t_light *light);
void						initialize_scene(t_scene *scene);
void						init_hash_table(unsigned char hash[512]);
int							parse(const char *file_name, t_scene *scene);
void						*render(void *arg);
void						rasterize(t_scene *scene);
t_vector					trace_container(t_ray ray,
										t_scene *scene,
										t_vector *color,
										int depth);
t_intersection				intersect_scene(t_ray ray, t_scene *scene);
void						calculate_world_intersection(t_object *object,
									t_ray world_ray,
									t_intersection *intersection);
int							test_intersection(t_scene *scene, t_object *object,
									t_ray ray, t_intersection *intersection);
t_inter						inter_sphere(t_ray obj_ray, t_object *object);
t_inter						inter_cylinder(t_ray obj_ray, t_object *object);
t_inter						inter_cone(t_ray obj_ray, t_object *object);
t_inter						inter_plane(t_ray obj_ray, t_object *object);
t_intersection				inter_scene(t_node *all, t_ray ray);
t_ray						calculate_refracted_ray(t_intersection intersection,
											t_refraction_data *r,
											t_vector *normal);
void						refract(t_vector *color,
								t_intersection intersection,
								t_scene *scene,
								int depth);
double						randomize(double start, int subdiv, double range);
void						build_light_matrices(t_scene *scene);
void						kill_sdl(t_scene *scene, char *str, int fd);
t_intersection				inter_to_intersection(t_intersection touch,
								t_ray ray);
t_intersection				inter_light(t_node *all, t_ray ray);
void						randomize_vector(t_vector *vector,
								int i, t_light *light, int sh_grain);
void						shadowing(t_vector *tmp_color,
							t_intersection intersection,
							t_scene *scene,
							t_light *light);
t_intersection				intersect_scene(t_ray ray, t_scene *scene);
int							intersect_bbox(t_ray ray, t_bbox bbox);
t_object					*add_object(t_scene *scene, int type);
#endif
